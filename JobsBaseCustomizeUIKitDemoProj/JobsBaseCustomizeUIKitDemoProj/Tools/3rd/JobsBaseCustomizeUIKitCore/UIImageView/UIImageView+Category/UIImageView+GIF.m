//
//  UIImageView+GIF.m
//  UIImage+GIF
//
//  Created by JieLee on 15/3/17.
//  Copyright (c) 2015年 PUPBOSS. All rights reserved.
//

#import "UIImageView+GIF.h"

@implementation UIImageView (GIF)

+ (UIImageView *)imageViewWithGIFFile:(NSString *)file
                                frame:(CGRect)frame{
    UIImageView *imageView = [[UIImageView alloc] initWithFrame:frame];
    
    // 加载gif文件数据
    NSData *gifData = [NSData dataWithContentsOfFile:file];
    // GIF动画图片数组
    NSMutableArray *frames = nil;
    // 图像源引用
    CGImageSourceRef src = CGImageSourceCreateWithData((__bridge CFDataRef) gifData, NULL);
    // 动画时长
    CGFloat animationTime = 0.f;
    
    if (src) {
        // 获取gif图片的帧数
        size_t count = CGImageSourceGetCount(src);
        // 实例化图片数组
        frames = [NSMutableArray arrayWithCapacity:count];
        
        for (size_t i = 0; i < count; i++) {
            // 获取指定帧图像
            CGImageRef image = CGImageSourceCreateImageAtIndex(src, i, NULL);
            
            // 获取GIF动画时长
            NSDictionary *properties = (__bridge NSDictionary *)CGImageSourceCopyPropertiesAtIndex(src, i, NULL);
            NSDictionary *frameProperties = [properties objectForKey:(NSString *)kCGImagePropertyGIFDictionary];
            NSNumber *delayTime = [frameProperties objectForKey:(NSString *)kCGImagePropertyGIFUnclampedDelayTime];
            animationTime += [delayTime floatValue];
            
            if (image) {
                [frames addObject:[UIImage imageWithCGImage:image]];
                CGImageRelease(image);
            }
        }
        
        CFRelease(src);
    }
    
    [imageView setImage:[frames objectAtIndex:0]];
    [imageView setAnimationImages:frames];
    [imageView setAnimationDuration:animationTime];
    [imageView startAnimating];
    
    return imageView;
}

@end

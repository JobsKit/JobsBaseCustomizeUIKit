//
//  NSUserDefaults+Manager.h
//  Casino
//
//  Created by Jobs on 2021/12/1.
//

#import <Foundation/Foundation.h>
#import "UserDefaultModel.h"

#if __has_include(<MJExtension/MJExtension.h>)
#import <MJExtension/MJExtension.h>
#else
#import "MJExtension.h"
#endif

#ifndef SetUserDefaultKeyWithValue
#define SetUserDefaultKeyWithValue(key,value) [NSUserDefaults.standardUserDefaults setValue:value forKey:key]
#endif

#ifndef SetUserDefaultKeyWithObject
#define SetUserDefaultKeyWithObject(key,object) [NSUserDefaults.standardUserDefaults setObject:object forKey:key]
#endif

#ifndef SetUserBoolKeyWithObject
#define SetUserBoolKeyWithObject(key,object) [NSUserDefaults.standardUserDefaults setBool:object forKey:key]
#endif

#ifndef GetUserDefaultValueForKey
#define GetUserDefaultValueForKey(key) [NSUserDefaults.standardUserDefaults valueForKey:key]
#endif

#ifndef GetUserDefaultObjForKey
#define GetUserDefaultObjForKey(key) [NSUserDefaults.standardUserDefaults objectForKey:key]
#endif

#ifndef GetUserDefaultBoolForKey
#define GetUserDefaultBoolForKey(key) [NSUserDefaults.standardUserDefaults boolForKey:key]
#endif

#ifndef DeleUserDefaultWithKey
#define DeleUserDefaultWithKey(key) [NSUserDefaults.standardUserDefaults removeObjectForKey:key]
#endif

#ifndef UserDefaultSynchronize
#define UserDefaultSynchronize NSUserDefaults.standardUserDefaults.synchronize
#endif

NS_ASSUME_NONNULL_BEGIN

@interface NSUserDefaults (Manager)

// 存数据【对象类型】对象会转化为json字符串进行存储，因为没有被序列化所以直接存不进去
+(void)updateWithModel:(UserDefaultModel *)userDefaultModel;
// 读取数据【读取出来是Json字符串,需要在外层用mj_objectWithKeyValues进行解析】
+(id _Nullable)readWithKey:(NSString *)key;
// 删除数据
+(void)deleteWithKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END

//
//  AppDelegate.h
//  JobsBaseCustomizeUIKitDemoProj
//
//  Created by Jobs on 2021/4/21.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (readonly, strong) NSPersistentCloudKitContainer *persistentContainer;

- (void)saveContext;


@end


//
//  TDCNotificationUtil.m
//  CityLove
//
//  Created by chengxi on 2016/12/2.
//  Copyright © 2016年 chengxi. All rights reserved.
//

#import "TDCNotificationUtil.h"

@implementation TDCNotificationUtil

+ (void)registerNotification:(NSString *)notificationName Observer:(id)observer Selector:(SEL)selector object:(id) object{
    [[NSNotificationCenter defaultCenter] addObserver:observer selector:selector name:notificationName object:object];
}

+ (void)postNotificationName:(NSString *)notificationName withObject:(id)object
{
    [[NSNotificationCenter defaultCenter] postNotificationName:notificationName object:object];
}

#pragma mark 移除通知监听
+ (void)unRegisterNotification:(NSString *)notificationName Observer:(id)observer
{
    [[NSNotificationCenter defaultCenter] removeObserver:observer name:notificationName object:nil];
}

/**
 *  发送本地通知
 */
+ (void)postLocalNotification:(NSString *)content
{
    NSDate * itemDate = [NSDate date];
    UILocalNotification *localNotif = [[UILocalNotification alloc] init];
    localNotif.fireDate = [itemDate dateByAddingTimeInterval:3];
    localNotif.timeZone = [NSTimeZone defaultTimeZone];
    localNotif.alertBody = content;
    localNotif.alertAction = NSLocalizedString(@"查看", nil);
    localNotif.soundName = UILocalNotificationDefaultSoundName;
    localNotif.applicationIconBadgeNumber = 0;
    [[UIApplication sharedApplication] scheduleLocalNotification:localNotif];
}

@end

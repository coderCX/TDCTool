//
//  TDCNotificationUtil.h
//  CityLove
//
//  Created by chengxi on 2016/12/2.
//  Copyright © 2016年 chengxi. All rights reserved.
//   通知类，用于项目内快速发送通知

#import <Foundation/Foundation.h>

@interface TDCNotificationUtil : NSObject

/**
 注册一个可以携带参数的通知

 @param notificationName 通知标志（唯一区分字符串）
 @param observer         通知接受对象
 @param selector         接受到通知需要处理的事件
 @param object           发送对象
 */
+ (void)registerNotification:(NSString *)notificationName Observer:(id)observer Selector:(SEL)selector object:(id) object;


/**
 发送一个可以携带参数的通知

 @param notificationName 通知标志（唯一区分字符串）
 @param object           发送对象
 */
+ (void)postNotificationName:(NSString *)notificationName withObject:(id)object;

/**
 注销通知

 @param notificationName 通知标志（唯一区分字符串）
 @param observer         通知接受对象
 */
+ (void)unRegisterNotification:(NSString *)notificationName Observer:(id)observer;

/**
 *  发送本地通知
 */
+ (void)postLocalNotification:(NSString *)content;

@end

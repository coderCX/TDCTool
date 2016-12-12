//
//  TDCTool.h
//  CityLove
//
//  Created by chengxi on 2016/12/2.
//  Copyright © 2016年 chengxi. All rights reserved.
//

#ifndef TDCTool_h
#define TDCTool_h

#import "TDCNotificationUtil.h"
#import "TDCAlertController.h"

/**
 系统日志
 */
#ifdef DEBUG
#define TDCLog(...) NSLog(__VA_ARGS__)
#define TDCLogIf(b, ...) if (b)\
NSLog(__VA_ARGS__)
#else
#define TDCLog(...)
#define TDCLogIf(b, ...)
#endif


//---------------------   常量类   --------------------------------------
/**
 产生随机色
 */
#define TDCRandomColor ([UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0])

/**
 GCD  几秒后执行某个方法
 不可控
 */
#define TDCAFTER(time, block) dispatch_after(dispatch_time(DISPATCH_TIME_NOW, time*NSEC_PER_SEC), dispatch_get_main_queue(), block)


// iphone4s适配用
#define IS_IPHONE_4S (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double)480)<DBL_EPSILON)
// iphone5适配用
#define IS_IPHONE_5 (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double)568)<DBL_EPSILON)
// iphone6适配用
#define IS_IPHONE_6 (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double)667)<DBL_EPSILON)
// iphone6Plus适配用
#define IS_IPHONE_6Plus (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double)736)<DBL_EPSILON)

/** 
 屏幕宽高 
 */
#define TDC_SCREEN_WIDTH     ([UIScreen mainScreen].bounds.size.width)
#define TDC_SCREEN_HEIGHT    ([UIScreen mainScreen].bounds.size.height)

/**
 block中弱引用self
 */
#define WEAKSELF typeof(self) __weak weakSelf = self;

/**
 返回应用代理AppDelegate实例对象
 */
#define TDCApp_Delegate ((AppDelegate *)[[UIApplication sharedApplication] delegate])

/**
 沙盒存储
 */
#define TDCUserDefaults    [NSUserDefaults standardUserDefaults]


/**
 正则表达式
 */
#define TDCREGEX_MOBILE        @"^[1]([3|4|5|7|8][0-9]{1})[0-9]{8}$"
#define TDCREGEX_EMAIL         @"^([a-z0-9A-Z]+[-|\\.]?)+[a-z0-9A-Z]@([a-z0-9A-Z]+(-[a-z0-9A-Z]+)?\\.)+[a-zA-Z]{2,}$"
#define TDCREGEX_PASSWORD      @"^[a-z0-9A-Z]{6,20}$"

#endif /* TDCTool_h */

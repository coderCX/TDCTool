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

#endif /* TDCTool_h */

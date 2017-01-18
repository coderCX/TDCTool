//
//  TDCAlertController.h
//  CityLove
//
//  Created by chengxi on 2016/12/8.
//  Copyright © 2016年 chengxi. All rights reserved.
//         TDCAlertController *alertVC = [TDCAlertController alertControllerWithTitle:@"提示" message:@"XXXXX"];
//         alertVC.alertBlock = ^(){};
//        [self presentViewController:alertVC animated:NO completion:nil];

#import <UIKit/UIKit.h>

/**
 点击确定按钮之后触发这个Block
 */
typedef void(^ AlertBlcok)(NSInteger tag);


@interface TDCAlertController : UIViewController

/**
 快速创建一个对话框

 @param title 标题提示
 @param message 内容
 @return 对话框
 */
+ (instancetype)alertControllerWithTitle:(NSString *)title message:(NSString *)message;


/**
 顶部 title
 */
@property (nonatomic, copy) NSString *topTitle;


/**
 顶部 title 文字颜色
 */
@property (nonatomic, strong) UIColor *topTitleColor;

/**
 顶部title背景色
 */
@property (nonatomic, strong) UIColor *topTitleViewColor;

/**
 关闭按钮文字
 */
@property (nonatomic, copy) NSString *cancelButtonTitle;

/**
 确认按钮文字
 */
@property (nonatomic, copy) NSString *sureButtonTitle;

/**
 消息内容
 */
@property (nonatomic, copy) NSString *message;


/**
 确认按钮文字颜色
 */
@property (nonatomic, strong) UIColor *sureButtonTitleColor;


/**
 是否只有一个确定按钮  默认NO
 */
@property (nonatomic,assign) BOOL isSure;


/**
 背景蒙层颜色
 */
@property (nonatomic, strong) UIColor *maskViewColor;


/**
 alertBlock = ^(){};   //无返回值的block
 */
@property (nonatomic, strong) AlertBlcok alertBlock;

@end

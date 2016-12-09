//
//  TDCAlertController.m
//  CityLove
//
//  Created by chengxi on 2016/12/8.
//  Copyright © 2016年 chengxi. All rights reserved.
//

#import "TDCAlertController.h"

#define kBasicH 90  //基础高度
#define kMarginW 30  //间距

@interface TDCAlertController ()
/**
 提示
 */
@property (weak, nonatomic) IBOutlet UILabel *titleLabel;

/**
 内容
 */
@property (weak, nonatomic) IBOutlet UILabel *contentLabel;

/**
 背景高度
 */
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *backViewH;

/**
 背景
 */
@property (weak, nonatomic) IBOutlet UIView *backView;

@property (weak, nonatomic) IBOutlet UIView *titleBackView;
@property (weak, nonatomic) IBOutlet UIButton *sureButton;


/**
 单个确认按钮
 */
@property (weak, nonatomic) IBOutlet UIButton *singleButton;

@end

@implementation TDCAlertController

- (instancetype)init
{
    if (self = [super init])
    {
        
        // 自定义Present样式，设置此种样式可以避免黑色背景
        self.modalPresentationStyle = UIModalPresentationCustom;
        self.view.backgroundColor = [UIColor clearColor];
        
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
}

- (void)viewDidLayoutSubviews
{
    _backView.clipsToBounds = YES;
    [_backView.layer setCornerRadius:4];
    
    // 控件布局
    CGFloat screenW = [UIScreen mainScreen].bounds.size.width;
    CGSize contentSize = [self.contentLabel sizeThatFits:CGSizeMake(screenW-80,60)];
    _backViewH.constant = kBasicH + contentSize.height;
    
    _backView.alpha = 0;
    _backView.transform = CGAffineTransformMakeScale(1.2, 1.2);
    [UIView animateWithDuration:0.5 delay:0 usingSpringWithDamping:0.55 initialSpringVelocity:10 options:UIViewAnimationOptionCurveEaseIn animations:^{
        _backView.transform = CGAffineTransformIdentity;
        _backView.alpha = 1;
    } completion:nil];
    
    if (_isSure)
    {
        _singleButton.hidden = NO;
        [_singleButton setBackgroundColor:[UIColor whiteColor]];
    }else
    {
        _singleButton.hidden = YES;
    }
}

+ (instancetype)alertControllerWithTitle:(NSString *)title message:(NSString *)message
{
    TDCAlertController *instance = [TDCAlertController new];
    instance.topTitle = title;
    instance.message = message;
    return instance;
}

- (void)setMessage:(NSString *)message
{
    _message = message;
    _contentLabel.text = message;
}

- (void)setTopTitle:(NSString *)topTitle
{
    _topTitle = topTitle;
    _titleLabel.text = topTitle;
}

- (void)setTopTitleColor:(UIColor *)topTitleColor
{
    _topTitleColor = topTitleColor;
    _titleLabel.textColor = topTitleColor;
}

- (void)setTopTitleViewColor:(UIColor *)topTitleViewColor
{
    _topTitleViewColor = topTitleViewColor;
    _titleBackView.backgroundColor = topTitleViewColor;
}

- (void)setSureButtonTitleColor:(UIColor *)sureButtonTitleColor
{
    _sureButtonTitleColor = sureButtonTitleColor;
    [_sureButton setTitleColor:sureButtonTitleColor forState:UIControlStateNormal];
}

- (void)setMaskViewColor:(UIColor *)maskViewColor
{
    _maskViewColor = maskViewColor;
    self.view.backgroundColor = maskViewColor;
}

- (void)setIsSure:(BOOL)isSure
{
    _isSure = isSure;
}

- (IBAction)cancelClick:(id)sender
{
    [self dismissSelf];
}

- (IBAction)sureClick:(id)sender
{
    [self dismissSelf];
    
    if (self.alertBlock)
    {
         self.alertBlock();
    }
   
}

- (IBAction)singleSureClick:(id)sender {
  
    [self dismissSelf];
    
    if (self.alertBlock)
    {
        self.alertBlock();
    }
}

- (void) dismissSelf
{
    [UIView animateWithDuration:0.1 animations:^{
        _backView.alpha = 0;
    } completion:^(BOOL finished) {
        [self dismissViewControllerAnimated:NO completion:nil];
    }];
}

@end

//
//  Demo3ViewController.m
//  AdView
//
//  Created by QzydeMac on 15/7/15.
//  Copyright (c) 2015年 Qzy. All rights reserved.
//

#import "Demo3ViewController.h"
#import "ZYBanner.h"
#import "AdView.h"

@interface Demo3ViewController ()
{
    AdView * adView;
}
@end

@implementation Demo3ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = @"模型加载网络图片";
    CGFloat width = [UIScreen mainScreen].bounds.size.width;
    //模型处理只支持网络,本地应该没有用途
    NSArray *imagesURL = @[
                           @"https://ss0.baidu.com/-Po3dSag_xI4khGko9WTAnF6hhy/super/whfpf%3D425%2C260%2C50/sign=a41eb338dd33c895a62bcb3bb72e47c2/5fdf8db1cb134954a2192ccb524e9258d1094a1e.jpg",
                           @"http://c.hiphotos.baidu.com/image/w%3D400/sign=c2318ff84334970a4773112fa5c8d1c0/b7fd5266d0160924c1fae5ccd60735fae7cd340d.jpg",
                           @"http://www.5858baypgs.com/img/aHR0cDovL3BpYzE4Lm5pcGljLmNvbS8yMDEyMDEwNS8xMDkyOTU0XzA5MzE1MTMzOTExNF8yLmpwZw==.jpg"
                           ];
    
    // 情景三：图片配文字(可选)
    NSArray *titles = @[@"感谢您的支持，如果下载的",
                        @"代码在使用过程中出现问题",
                        @"您可以发邮件到qzycoder@163.com",
                        ];
    
    //如果你的这个广告视图是添加到导航控制器子控制器的View上,请添加此句,否则可忽略此句
    self.automaticallyAdjustsScrollViewInsets = NO;
    
    NSMutableArray * models = [[NSMutableArray alloc]init];
    for (int i = 0; i < 3; i++)
    {
        ZYBanner * banner = [[ZYBanner alloc]init];
        banner.imageURL = imagesURL[i];
        banner.bannerName = titles[i];
        [models addObject:banner];
    }
    adView = [AdView adScrollViewWithFrame:CGRectMake(0, 64, width, 172) modelArr:models imagePropertyName:@"imageURL" pageControlShowStyle:UIPageControlShowStyleLeft];
    [adView setAdTitlePropertyName:@"bannerName" withShowStyle:AdTitleShowStyleRight];
    
    //    是否需要支持定时循环滚动，默认为YES
    //    adView.isNeedCycleRoll = YES;
    
    //    设置图片滚动时间,默认3s
    adView.adMoveTime = 5.0;
    
    //图片被点击后回调的方法
    adView.callBackForModel = ^(ZYBanner * banner)
    {
        NSLog(@"%@--%@",banner.imageURL,banner.bannerName);
    };
    [self.view addSubview:adView];
}
@end

#import "Demo2Controller.h"
#import "AdView.h"

@interface Demo2Controller ()
{
    AdView * adView;
}
@end

@implementation Demo2Controller

- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    self.title = @"加载本地图片";
    CGFloat width = [UIScreen mainScreen].bounds.size.width;
    NSArray *imagesURL = @[
                           @"123.jpg",
                           @"456.jpg",
                           @"789.jpg",
                           ];
    
    // 情景三：图片配文字(可选)
    NSArray *titles = @[@"感谢您的支持，如果下载的",
                        @"代码在使用过程中出现问题",
                        @"您可以发邮件到qzycoder@163.com",
                        ];
    
    //如果你的这个广告视图是添加到导航控制器子控制器的View上,请添加此句,否则可忽略此句
    self.automaticallyAdjustsScrollViewInsets = NO;
    
    adView = [AdView adScrollViewWithFrame:CGRectMake(0, 64, width, 172) localImageLinkURL:imagesURL  pageControlShowStyle:UIPageControlShowStyleLeft];
    
    //    是否需要支持定时循环滚动，默认为YES
    //    adView.isNeedCycleRoll = YES;
    
    [adView setAdTitleArray:titles withShowStyle:AdTitleShowStyleRight];
    //    设置图片滚动时间,默认3s
    adView.adMoveTime = 5.0;
    
    //图片被点击后回调的方法
    adView.callBack = ^(NSInteger index,NSString * imageURL)
    {
        NSLog(@"被点中图片的索引:%ld---地址:%@",index,imageURL);
    };
    [self.view addSubview:adView];
}
@end

广告循环滚动
类似淘宝，网易新闻首页广告栏效果，需要sdwebImage的支持，仅仅只需要额外导入一个类文件！使用方法如下：
    CGFloat width = [UIScreen mainScreen].bounds.size.width;
    
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
    //网络图片加载方法
    adView = [AdView adScrollViewWithFrame:CGRectMake(0, 64, width, 172) imageLinkURL:imagesURL placeHoderImageName:@"placeHoder.jpg" pageControlShowStyle:UIPageControlShowStyleLeft];
    
    
//    是否需要支持定时循环滚动，默认为YES
//    adView.isNeedCycleRoll = YES;
    
    [adView setAdTitleArray:titles withShowStyle:AdTitleShowStyleRight];
//    设置图片滚动时间,默认3s
//    adView.adMoveTime = 2.0;
    
    //图片被点击后回调的方法
    adView.callBack = ^(NSInteger index,NSString * imageURL)
    {
        NSLog(@"被点中图片的索引:%ld---地址:%@",index,imageURL);
    };
    [self.view addSubview:adView];




    //本地图片加载方法
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

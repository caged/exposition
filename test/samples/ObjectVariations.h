@protocol TODBrowserPlugInController
- (id)version;
- (id)mainWebView;
- (id)webViews;
- (id)plugInSupportDirPath;
- (void)loadRequest:(id)arg1 inNewTabInBackground:(BOOL)arg2;
- (void)loadRequest:(id)arg1 inNewWindowInBackground:(BOOL)arg2;
- (void)showStatusText:(id)arg1;
- (void)registerForUserscriptExecutionInWebView:(id)arg1;
- (void)unregisterForUserscriptExecutionInWebView:(id)arg1;
@end
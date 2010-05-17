@protocol GrowlApplicationBridgeDelegate
@end

@protocol NSCoding
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
@end

@protocol NSObject
- (BOOL)isEqual:(id)arg1;
- (unsigned int)hash;
- (Class)superclass;
- (Class)class;
- (id)self;
- (struct _NSZone *)zone;
- (id)performSelector:(SEL)arg1;
- (id)performSelector:(SEL)arg1 withObject:(id)arg2;
- (id)performSelector:(SEL)arg1 withObject:(id)arg2 withObject:(id)arg3;
- (BOOL)isProxy;
- (BOOL)isKindOfClass:(Class)arg1;
- (BOOL)isMemberOfClass:(Class)arg1;
- (BOOL)conformsToProtocol:(id)arg1;
- (BOOL)respondsToSelector:(SEL)arg1;
- (id)retain;
- (oneway void)release;
- (id)autorelease;
- (unsigned int)retainCount;
- (id)description;
@end

@protocol PSMTabStyle <NSObject>
- (id)name;
- (float)leftMarginForTabBarControl;
- (float)rightMarginForTabBarControl;
- (id)addTabButtonImage;
- (id)addTabButtonPressedImage;
- (id)addTabButtonRolloverImage;
- (struct _NSRect)closeButtonRectForTabCell:(id)arg1;
- (struct _NSRect)iconRectForTabCell:(id)arg1;
- (struct _NSRect)indicatorRectForTabCell:(id)arg1;
- (struct _NSRect)objectCounterRectForTabCell:(id)arg1;
- (float)minimumWidthOfTabCell:(id)arg1;
- (float)desiredWidthOfTabCell:(id)arg1;
- (id)attributedObjectCountValueForTabCell:(id)arg1;
- (id)attributedStringValueForTabCell:(id)arg1;
- (void)drawTabCell:(id)arg1;
- (void)drawTabBar:(id)arg1 inRect:(struct _NSRect)arg2;
@end

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

@protocol TODBrowserScriptingBridge <NSObject>
- (void)handleWebFrame:(id)arg1;
@end

@protocol TODTinyURLResolverDelegate <NSObject>
- (void)tinyURLResolver:(id)arg1 didResolveURLString:(id)arg2 fromTinyURLString:(id)arg3;
- (void)tinyURLResolver:(id)arg1 failedToResolveTinyURLString:(id)arg2;
@end

@interface PSMAquaTabStyle : NSObject <PSMTabStyle>
{
    NSImage *aquaTabBg;
    NSImage *aquaTabBgDown;
    NSImage *aquaTabBgDownGraphite;
    NSImage *aquaTabBgDownNonKey;
    NSImage *aquaDividerDown;
    NSImage *aquaDivider;
    NSImage *aquaCloseButton;
    NSImage *aquaCloseButtonDown;
    NSImage *aquaCloseButtonOver;
    NSImage *_addTabButtonImage;
    NSImage *_addTabButtonPressedImage;
    NSImage *_addTabButtonRolloverImage;
}

- (id)name;
- (id)init;
- (void)loadImages;
- (void)dealloc;
- (float)leftMarginForTabBarControl;
- (float)rightMarginForTabBarControl;
- (id)addTabButtonImage;
- (id)addTabButtonPressedImage;
- (id)addTabButtonRolloverImage;
- (struct _NSRect)closeButtonRectForTabCell:(id)arg1;
- (struct _NSRect)iconRectForTabCell:(id)arg1;
- (struct _NSRect)indicatorRectForTabCell:(id)arg1;
- (struct _NSRect)objectCounterRectForTabCell:(id)arg1;
- (float)minimumWidthOfTabCell:(id)arg1;
- (float)desiredWidthOfTabCell:(id)arg1;
- (id)attributedObjectCountValueForTabCell:(id)arg1;
- (id)attributedStringValueForTabCell:(id)arg1;
- (void)drawTabCell:(id)arg1;
- (void)drawTabBar:(id)arg1 inRect:(struct _NSRect)arg2;
- (void)drawInteriorWithTabCell:(id)arg1 inView:(id)arg2;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;

@end

@interface PSMMetalTabStyle : NSObject <PSMTabStyle>
{
    NSImage *metalCloseButton;
    NSImage *metalCloseButtonDown;
    NSImage *metalCloseButtonOver;
    NSImage *_addTabButtonImage;
    NSImage *_addTabButtonPressedImage;
    NSImage *_addTabButtonRolloverImage;
}

- (id)name;
- (id)init;
- (void)dealloc;
- (float)leftMarginForTabBarControl;
- (float)rightMarginForTabBarControl;
- (id)addTabButtonImage;
- (id)addTabButtonPressedImage;
- (id)addTabButtonRolloverImage;
- (struct _NSRect)closeButtonRectForTabCell:(id)arg1;
- (struct _NSRect)iconRectForTabCell:(id)arg1;
- (struct _NSRect)indicatorRectForTabCell:(id)arg1;
- (struct _NSRect)objectCounterRectForTabCell:(id)arg1;
- (float)minimumWidthOfTabCell:(id)arg1;
- (float)desiredWidthOfTabCell:(id)arg1;
- (id)attributedObjectCountValueForTabCell:(id)arg1;
- (id)attributedStringValueForTabCell:(id)arg1;
- (void)drawTabCell:(id)arg1;
- (void)drawInteriorWithTabCell:(id)arg1 inView:(id)arg2;
- (void)drawTabBar:(id)arg1 inRect:(struct _NSRect)arg2;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;

@end

@interface PSMOverflowPopUpButton : NSPopUpButton
{
    NSImage *_PSMTabBarOverflowPopUpImage;
    NSImage *_PSMTabBarOverflowDownPopUpImage;
    BOOL _down;
}

- (id)initWithFrame:(struct _NSRect)arg1 pullsDown:(BOOL)arg2;
- (void)dealloc;
- (void)drawRect:(struct _NSRect)arg1;
- (void)mouseDown:(id)arg1;
- (void)notificationReceived:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;

@end

@interface PSMProgressIndicator : NSProgressIndicator
{
}

- (void)setHidden:(BOOL)arg1;

@end

@interface PSMRolloverButton : NSButton
{
    NSImage *_rolloverImage;
    NSImage *_usualImage;
    int _myTrackingRectTag;
}

- (void)dealloc;
- (void)setUsualImage:(id)arg1;
- (id)usualImage;
- (void)setRolloverImage:(id)arg1;
- (id)rolloverImage;
- (void)addTrackingRect;
- (void)removeTrackingRect;
- (void)mouseEntered:(id)arg1;
- (void)mouseExited:(id)arg1;
- (void)mouseDown:(id)arg1;
- (void)resetCursorRects;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;

@end

@interface PSMTabBarCell : NSActionCell
{
    struct _NSRect _frame;
    struct _NSSize _stringSize;
    int _currentStep;
    BOOL _isPlaceholder;
    int _tabState;
    int _closeButtonTrackingTag;
    int _cellTrackingTag;
    BOOL _closeButtonOver;
    BOOL _closeButtonPressed;
    PSMProgressIndicator *_indicator;
    BOOL _isInOverflowMenu;
    BOOL _hasCloseButton;
    BOOL _isCloseButtonSuppressed;
    BOOL _hasIcon;
    int _count;
}

- (id)initWithControlView:(id)arg1;
- (id)initPlaceholderWithFrame:(struct _NSRect)arg1 expanded:(BOOL)arg2 inControlView:(id)arg3;
- (void)dealloc;
- (id)controlView;
- (void)setControlView:(id)arg1;
- (int)closeButtonTrackingTag;
- (void)setCloseButtonTrackingTag:(int)arg1;
- (int)cellTrackingTag;
- (void)setCellTrackingTag:(int)arg1;
- (float)width;
- (struct _NSRect)frame;
- (void)setFrame:(struct _NSRect)arg1;
- (void)setStringValue:(id)arg1;
- (struct _NSSize)stringSize;
- (id)attributedStringValue;
- (int)tabState;
- (void)setTabState:(int)arg1;
- (id)indicator;
- (BOOL)isInOverflowMenu;
- (void)setIsInOverflowMenu:(BOOL)arg1;
- (BOOL)closeButtonPressed;
- (void)setCloseButtonPressed:(BOOL)arg1;
- (BOOL)closeButtonOver;
- (void)setCloseButtonOver:(BOOL)arg1;
- (BOOL)hasCloseButton;
- (void)setHasCloseButton:(BOOL)arg1;
- (void)setCloseButtonSuppressed:(BOOL)arg1;
- (BOOL)isCloseButtonSuppressed;
- (BOOL)hasIcon;
- (void)setHasIcon:(BOOL)arg1;
- (int)count;
- (void)setCount:(int)arg1;
- (BOOL)isPlaceholder;
- (void)setIsPlaceholder:(BOOL)arg1;
- (int)currentStep;
- (void)setCurrentStep:(int)arg1;
- (struct _NSRect)indicatorRectForFrame:(struct _NSRect)arg1;
- (struct _NSRect)closeButtonRectForFrame:(struct _NSRect)arg1;
- (float)minimumWidthOfCell;
- (float)desiredWidthOfCell;
- (void)drawWithFrame:(struct _NSRect)arg1 inView:(id)arg2;
- (void)mouseEntered:(id)arg1;
- (void)mouseExited:(id)arg1;
- (id)dragImageForRect:(struct _NSRect)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;

@end

@interface PSMTabBarControl : NSControl
{
    NSMutableArray *_cells;
    NSTabView *tabView;
    PSMOverflowPopUpButton *_overflowPopUpButton;
    PSMRolloverButton *_addTabButton;
    id <PSMTabStyle> style;
    BOOL _canCloseOnlyTab;
    BOOL _hideForSingleTab;
    BOOL _hideAlways;
    BOOL _showAddTabButton;
    BOOL _sizeCellsToFit;
    int _cellMinWidth;
    int _cellMaxWidth;
    int _cellOptimumWidth;
    int _currentStep;
    BOOL _isHidden;
    BOOL _hideIndicators;
    id partnerView;
    BOOL _awakenedFromNib;
    NSEvent *_lastMouseDownEvent;
    BOOL _allowsDragBetweenWindows;
    id delegate;
}

+ (id)bundle;
- (float)availableCellWidth;
- (struct _NSRect)genericCellRect;
- (void)initAddedProperties;
- (id)initWithFrame:(struct _NSRect)arg1;
- (void)dealloc;
- (void)awakeFromNib;
- (id)cells;
- (id)lastMouseDownEvent;
- (void)setLastMouseDownEvent:(id)arg1;
- (id)delegate;
- (void)setDelegate:(id)arg1;
- (id)tabView;
- (void)setTabView:(id)arg1;
- (id)style;
- (id)styleName;
- (void)setStyleNamed:(id)arg1;
- (BOOL)canCloseOnlyTab;
- (void)setCanCloseOnlyTab:(BOOL)arg1;
- (BOOL)allowsDragBetweenWindows;
- (void)setAllowsDragBetweenWindows:(BOOL)arg1;
- (BOOL)hideForSingleTab;
- (void)setHideForSingleTab:(BOOL)arg1;
- (BOOL)hideAlways;
- (void)setHideAlways:(BOOL)arg1;
- (BOOL)showAddTabButton;
- (void)setShowAddTabButton:(BOOL)arg1;
- (int)cellMinWidth;
- (void)setCellMinWidth:(int)arg1;
- (int)cellMaxWidth;
- (void)setCellMaxWidth:(int)arg1;
- (int)cellOptimumWidth;
- (void)setCellOptimumWidth:(int)arg1;
- (BOOL)sizeCellsToFit;
- (void)setSizeCellsToFit:(BOOL)arg1;
- (id)addTabButton;
- (id)overflowPopUpButton;
- (void)addTabViewItem:(id)arg1;
- (void)removeTabForCell:(id)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)hideTabBar:(BOOL)arg1 animate:(BOOL)arg2;
- (void)animateShowHide:(id)arg1;
- (id)partnerView;
- (void)setPartnerView:(id)arg1;
- (BOOL)isFlipped;
- (void)drawRect:(struct _NSRect)arg1;
- (void)update;
- (BOOL)mouseDownCanMoveWindow;
- (BOOL)acceptsFirstMouse:(id)arg1;
- (void)mouseDown:(id)arg1;
- (void)mouseDragged:(id)arg1;
- (void)mouseUp:(id)arg1;
- (BOOL)shouldDelayWindowOrderingForEvent:(id)arg1;
- (unsigned int)draggingSourceOperationMaskForLocal:(BOOL)arg1;
- (BOOL)ignoreModifierKeysWhileDragging;
- (unsigned int)draggingEntered:(id)arg1;
- (unsigned int)draggingUpdated:(id)arg1;
- (void)draggingExited:(id)arg1;
- (BOOL)prepareForDragOperation:(id)arg1;
- (BOOL)performDragOperation:(id)arg1;
- (void)draggedImage:(id)arg1 endedAt:(struct _NSPoint)arg2 operation:(unsigned int)arg3;
- (void)concludeDragOperation:(id)arg1;
- (void)overflowMenuAction:(id)arg1;
- (void)closeTabClick:(id)arg1;
- (void)tabClick:(id)arg1;
- (void)tabNothing:(id)arg1;
- (void)frameDidChange:(id)arg1;
- (void)viewWillStartLiveResize;
- (void)viewDidEndLiveResize;
- (void)windowDidMove:(id)arg1;
- (void)windowStatusDidChange:(id)arg1;
- (void)tabView:(id)arg1 didSelectTabViewItem:(id)arg2;
- (BOOL)tabView:(id)arg1 shouldSelectTabViewItem:(id)arg2;
- (void)tabView:(id)arg1 willSelectTabViewItem:(id)arg2;
- (void)tabViewDidChangeNumberOfTabViewItems:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (struct _NSSize)minimumFrameSizeFromKnobPosition:(int)arg1;
- (struct _NSSize)maximumFrameSizeFromKnobPosition:(int)arg1;
- (void)placeView:(struct _NSRect)arg1;
- (id)representedTabViewItems;
- (id)cellForPoint:(struct _NSPoint)arg1 cellFrame:(struct _NSRect *)arg2;
- (id)lastVisibleTab;
- (int)numberOfVisibleTabs;

@end

@interface PSMTabDragAssistant : NSObject
{
    PSMTabBarControl *_sourceTabBar;
    PSMTabBarControl *_destinationTabBar;
    NSMutableSet *_participatingTabBars;
    PSMTabBarCell *_draggedCell;
    int _draggedCellIndex;
    BOOL _isDragging;
    NSTimer *_animationTimer;
    NSMutableArray *_sineCurveWidths;
    struct _NSPoint _currentMouseLoc;
    PSMTabBarCell *_targetCell;
}

+ (id)sharedDragAssistant;
- (id)init;
- (void)dealloc;
- (id)sourceTabBar;
- (void)setSourceTabBar:(id)arg1;
- (id)destinationTabBar;
- (void)setDestinationTabBar:(id)arg1;
- (id)draggedCell;
- (void)setDraggedCell:(id)arg1;
- (int)draggedCellIndex;
- (void)setDraggedCellIndex:(int)arg1;
- (BOOL)isDragging;
- (void)setIsDragging:(BOOL)arg1;
- (struct _NSPoint)currentMouseLoc;
- (void)setCurrentMouseLoc:(struct _NSPoint)arg1;
- (id)targetCell;
- (void)setTargetCell:(id)arg1;
- (void)startDraggingCell:(id)arg1 fromTabBar:(id)arg2 withMouseDownEvent:(id)arg3;
- (void)draggingEnteredTabBar:(id)arg1 atPoint:(struct _NSPoint)arg2;
- (void)draggingUpdatedInTabBar:(id)arg1 atPoint:(struct _NSPoint)arg2;
- (void)draggingExitedTabBar:(id)arg1;
- (void)performDragOperation;
- (void)draggedImageEndedAt:(struct _NSPoint)arg1 operation:(unsigned int)arg2;
- (void)finishDrag;
- (void)animateDrag:(id)arg1;
- (void)calculateDragAnimationForTabBar:(id)arg1;
- (void)distributePlaceholdersInTabBar:(id)arg1 withDraggedCell:(id)arg2;
- (void)distributePlaceholdersInTabBar:(id)arg1;
- (void)removeAllPlaceholdersFromTabBar:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;

@end

@interface PSMUnifiedTabStyle : NSObject <PSMTabStyle>
{
    NSImage *unifiedCloseButton;
    NSImage *unifiedCloseButtonDown;
    NSImage *unifiedCloseButtonOver;
    NSImage *_addTabButtonImage;
    NSImage *_addTabButtonPressedImage;
    NSImage *_addTabButtonRolloverImage;
    float leftMargin;
}

- (id)name;
- (id)init;
- (void)dealloc;
- (void)setLeftMarginForTabBarControl:(float)arg1;
- (float)leftMarginForTabBarControl;
- (float)rightMarginForTabBarControl;
- (id)addTabButtonImage;
- (id)addTabButtonPressedImage;
- (id)addTabButtonRolloverImage;
- (struct _NSRect)closeButtonRectForTabCell:(id)arg1;
- (struct _NSRect)iconRectForTabCell:(id)arg1;
- (struct _NSRect)indicatorRectForTabCell:(id)arg1;
- (struct _NSRect)objectCounterRectForTabCell:(id)arg1;
- (float)minimumWidthOfTabCell:(id)arg1;
- (float)desiredWidthOfTabCell:(id)arg1;
- (id)attributedObjectCountValueForTabCell:(id)arg1;
- (id)attributedStringValueForTabCell:(id)arg1;
- (void)drawTabCell:(id)arg1;
- (void)drawInteriorWithTabCell:(id)arg1 inView:(id)arg2;
- (void)drawTabBar:(id)arg1 inRect:(struct _NSRect)arg2;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;

@end

@interface HMRSSNodeFilter : NSObject <DOMNodeFilter>
{
}

+ (id)RSSMimes;
- (short)acceptNode:(id)arg1;

@end

@interface HMImageComboBox : NSComboBox
{
    NSMutableArray *_buttons;
    BOOL _shouldDrag;
}

+ (Class)cellClass;
- (id)initWithFrame:(struct _NSRect)arg1;
- (void)dealloc;
- (void)setImage:(id)arg1;
- (id)image;
- (id)buttons;
- (id)addButtonWithSize:(struct _NSSize)arg1;
- (id)buttonWithTag:(int)arg1;
- (void)removeButton:(id)arg1;
- (struct _NSRect)buttonFrame;
- (void)mouseDown:(id)arg1;
- (void)mouseDragged:(id)arg1;

@end

@interface HMImageComboBoxCell : NSComboBoxCell
{
    NSImage *_image;
}

- (id)initImageCell:(id)arg1;
- (id)initTextCell:(id)arg1;
- (void)dealloc;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)setImage:(id)arg1;
- (id)image;
- (struct _NSRect)imageFrameForCellFrame:(struct _NSRect)arg1;
- (void)selectWithFrame:(struct _NSRect)arg1 inView:(id)arg2 editor:(id)arg3 delegate:(id)arg4 start:(int)arg5 length:(int)arg6;
- (void)editWithFrame:(struct _NSRect)arg1 inView:(id)arg2 editor:(id)arg3 delegate:(id)arg4 event:(id)arg5;
- (void)drawInteriorWithFrame:(struct _NSRect)arg1 inView:(id)arg2;
- (void)drawInteriorImageOnlyWithFrame:(struct _NSRect)arg1 inView:(id)arg2;
- (struct _NSSize)cellSize;
- (void)_drawFocusRingWithFrame:(struct _NSRect)arg1;
- (id)imageForDraggingWithFrame:(struct _NSRect)arg1 inView:(id)arg2;
- (BOOL)imageTrackMouse:(id)arg1 inRect:(struct _NSRect)arg2 ofView:(id)arg3;
- (void)resetCursorRect:(struct _NSRect)arg1 inView:(id)arg2;
- (id)popUp;

@end

@interface CMController : NSObject
{
    NSMenu *topMenu;
    NSArrayController *scriptsController;
    NSMutableArray *scripts_;
    NSString *scriptDir_;
    NSString *scriptTemplate_;
    BOOL finishedUserscriptEval;
}

+ (id)instance;
- (id)init;
- (void)dealloc;
- (void)awakeFromNib;
- (void)registerForUserscriptNotifications:(id)arg1;
- (void)unregisterForUserscriptNotifications:(id)arg1;
- (id)loadScriptTemplate;
- (id)scripts;
- (id)scriptElementsDictionary;
- (void)saveScriptsConfig;
- (void)addScript:(id)arg1;
- (void)installScript:(id)arg1;
- (void)reloadMenu;
- (id)scriptsAtDir:(id)arg1;
- (void)showWarningAboutCreammonkey;
- (void)showWarningAboutGreaseKit_1_2;
- (void)installCreammonkeyScripts;
- (void)loadUserScripts;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (id)matchedScripts:(id)arg1;
- (void)installAlertDidEnd:(id)arg1 returnCode:(int)arg2 contextInfo:(void *)arg3;
- (void)showInstallAlertSheet:(id)arg1 webView:(id)arg2;
- (void)evalScriptsInFrame:(id)arg1 force:(BOOL)arg2;
- (BOOL)isSandboxView:(id)arg1;
- (void)progressStarted:(id)arg1;
- (void)progressChanged:(id)arg1;
- (void)didFinishLoadForMainFrame:(id)arg1;
- (void)toggleScriptEnable:(id)arg1;
- (void)uninstallSelected:(id)arg1;
- (void)orderFrontAboutPanel:(id)arg1;
- (void)reloadUserScripts:(id)arg1;
- (void)goToUserscriptsSite:(id)arg1;
- (void)userscriptDownloadDidFinish:(id)arg1;
- (void)windowWillClose:(id)arg1;
- (void)applicationDidFinishLaunching:(id)arg1;
- (BOOL)finishedUserscriptEval;
- (void)setFinishedUserscriptEval:(BOOL)arg1;

@end

@interface CMUserScript : NSObject
{
    NSString *script_;
    NSMutableArray *include_;
    NSMutableArray *exclude_;
    NSMutableSet *applications_;
    NSString *fullPath_;
    NSString *name_;
    NSString *namespace_;
    NSString *description_;
}

+ (void)setDummyBundleIdentifier:(id)arg1;
+ (id)fileNameFromString:(id)arg1;
+ (id)uniqueName:(id)arg1 others:(id)arg2;
+ (void)parseMetadataLine:(id)arg1 result:(id)arg2;
+ (id)parseMetadata:(id)arg1;
+ (id)patternsFromStrings:(id)arg1;
- (id)include;
- (void)setInclude:(id)arg1;
- (id)exclude;
- (void)setExclude:(id)arg1;
- (void)elements:(id)arg1 toPatterns:(id)arg2;
- (void)array:(id)arg1 toElements:(id)arg2 name:(id)arg3;
- (void)configureWithXMLElement:(id)arg1;
- (id)XMLElement;
- (BOOL)isEqualTo:(id)arg1;
- (BOOL)isInstalled:(id)arg1;
- (id)name;
- (void)setName:(id)arg1;
- (id)scriptDescription;
- (void)setScriptDescription:(id)arg1;
- (id)namespace;
- (void)setNamespace:(id)arg1;
- (id)script;
- (id)basenameFromName;
- (BOOL)install:(id)arg1;
- (BOOL)uninstall;
- (BOOL)isEnabled;
- (void)setEnabled:(BOOL)arg1;
- (BOOL)isMatched:(id)arg1 patterns:(id)arg2;
- (BOOL)isMatched:(id)arg1;
- (id)initWithString:(id)arg1 element:(id)arg2;
- (id)initWithData:(id)arg1 element:(id)arg2;
- (id)initWithContentsOfFile:(id)arg1 element:(id)arg2;
- (id)init;
- (void)dealloc;

@end

@interface WildcardPattern : NSObject
{
    NSString *source_;
    struct {
        int re_magic;
        unsigned int re_nsub;
        char *re_endp;
        struct re_guts *re_g;
    } pattern_;
}

+ (id)patternWithString:(id)arg1;
+ (id)escapeRegexpMetaCharactors:(id)arg1;
+ (id)regexpFromURIGlob:(id)arg1;
- (void)setString:(id)arg1;
- (id)string;
- (id)initWithString:(id)arg1;
- (BOOL)isMatch:(id)arg1;
- (void)dealloc;

@end

@interface TODAppDelegate : NSObject <GrowlApplicationBridgeDelegate>
{
    NSMenu *historyMenu;
    NSMenu *bookmarkMenu;
    NSStatusItem *statusItem;
    TODBrowserWindow *statusItemWindow;
    NSMenu *statusItemMenu;
    struct _NSPoint statusItemWindowFrameOrigin;
    BOOL statusItemVisible;
    BOOL statusItemMenuVisible;
    float statusItemWindowFrameX;
    NSTimer *didFinishLaunchingTimer;
    NSURL *homeURL;
    NSString *homeURLString;
    NSString *originalHomeURLString;
    NSArray *userAgentStrings;
    NSString *defaultUserAgentString;
    NSString *defaultUserAgentFormat;
    NSString *appName;
    NSMutableArray *matchingURLPatterns;
    NSDictionary *specialCases;
    BOOL fullScreen;
    BOOL isGmail;
    BOOL isGoogleApps;
    BOOL isGoogleReader;
    BOOL isYahooMail;
    BOOL isFacebook;
    BOOL isFlickr;
    BOOL isMobileMe;
    BOOL shouldCaptureWindowFrameString;
    NSString *googleAppsDomain;
    float updateDockTileInterval;
    NSString *appSupportDirPath;
    NSString *ssbSupportDirPath;
    NSString *userscriptDirPath;
    NSString *userstyleDirPath;
    NSString *userstyleFilePath;
    NSString *webHistoryFilePath;
    NSString *bookmarksFilePath;
    NSString *downloadArchiveFilePath;
    NSString *plugInPrivateDirPath;
    NSString *plugInDirPath;
    NSMutableArray *historyMenuObjects;
    NSMutableArray *bookmarks;
    unsigned int numIndividualItems;
    BOOL firstHistoryDateIsToday;
    BOOL hasHiddenWindow;
    NSScreen *fullScreenScreen;
    NSImageView *dockTileImageView;
}

+ (void)initialize;
+ (void)setupDefaults;
+ (id)instance;
+ (id)frontmostBrowserWindowController;
+ (void)registerValueTransformers;
- (id)init;
- (void)dealloc;
- (void)showDownloadsWindow:(id)arg1;
- (void)showBookmarksWindow:(id)arg1;
- (void)toggleFullScreen:(id)arg1;
- (void)toggleBlockPopUpWindows:(id)arg1;
- (void)toggleMenuExtraStatus:(id)arg1;
- (void)toggleEmbeddedStatus:(id)arg1;
- (void)addNewTab:(id)arg1;
- (void)doNewDocument:(id)arg1;
- (void)toggleBookmarkBarShown:(id)arg1;
- (void)toggleTabBarShown:(id)arg1;
- (void)toggleStatusBarShown:(id)arg1;
- (void)restoreDefaults:(id)arg1;
- (void)historyItemClicked:(id)arg1;
- (void)bookmarkClicked:(id)arg1;
- (void)clearHistory:(id)arg1;
- (void)revealUserscriptsDirectory:(id)arg1;
- (void)newUserscript:(id)arg1;
- (void)showWebInspector:(id)arg1;
- (void)showErrorConsole:(id)arg1;
- (void)showNetworkTimeline:(id)arg1;
- (BOOL)shouldLoadURL:(id)arg1;
- (id)matchingURLPatterns;
- (void)setMatchingURLPatterns:(id)arg1;
- (BOOL)URLStringStartsWithSupportedScheme:(id)arg1;
- (BOOL)URLStringStartsWithHTTPScheme:(id)arg1;
- (void)windowWillMove:(id)arg1;
- (void)windowDidMove:(id)arg1;
- (void)windowDidResize:(id)arg1;
- (BOOL)validateMenuItem:(id)arg1;
- (BOOL)applicationShouldOpenUntitledFile:(id)arg1;
- (BOOL)applicationShouldHandleReopen:(id)arg1 hasVisibleWindows:(BOOL)arg2;
- (BOOL)application:(id)arg1 openFile:(id)arg2;
- (void)application:(id)arg1 openFiles:(id)arg2;
- (void)killDidFinishLaunchingTimer;
- (void)fireApplicationsDidFinishLaunching;
- (void)applicationDidFinishLaunching:(id)arg1;
- (unsigned int)applicationShouldTerminate:(id)arg1;
- (void)applicationWillTerminate:(id)arg1;
- (void)applicationDidBecomeActive:(id)arg1;
- (void)applicationWillResignActive:(id)arg1;
- (int)numberOfItemsInBookmarkMenu:(id)arg1;
- (int)numberOfItemsInMenu:(id)arg1;
- (BOOL)bookmarkMenu:(id)arg1 updateItem:(id)arg2 atIndex:(int)arg3 shouldCancel:(BOOL)arg4;
- (BOOL)menu:(id)arg1 updateItem:(id)arg2 atIndex:(int)arg3 shouldCancel:(BOOL)arg4;
- (void)growlNotificationWasClicked:(id)arg1;
- (id)applicationNameForGrowl;
- (BOOL)checkForExpiredBeta;
- (void)updateAppNameInMainMenu;
- (void)loadUserAgentStrings;
- (void)setupUserAgentUI;
- (id)userAgentString;
- (id)defaultUserAgentString;
- (void)setUserAgentString:(id)arg1;
- (BOOL)isUsingDefaultUserAgent;
- (void)updateUserAgentStringsMenu;
- (void)changeUAStringAction:(id)arg1;
- (void)changeUAStringToOtherAction:(id)arg1;
- (void)updateUserAgentStringInAllWebViews;
- (void)setInitialMatchingURLPatterns;
- (void)readConfigPlist;
- (void)readSpecialCasesPlist;
- (void)setupBookmarksMenu;
- (void)loadBookmarks;
- (BOOL)createAppSupportDir;
- (BOOL)createDirAtPathIfDoesntExist:(id)arg1;
- (void)registerForAppleEventHandling;
- (void)setupWebPreferences;
- (BOOL)loadGearsIfPresent;
- (void)writeHistoryToDisk;
- (void)writeBookmarksToDisk;
- (void)writeDownloadsToDisk;
- (void)storeRecentURLs;
- (void)restoreSession;
- (void)storeSession;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)homeURLChanged;
- (void)checkHomeURLForSpecialAppSupport;
- (void)captureFrameStringForWindow:(id)arg1;
- (void)closeAllDocuments;
- (void)setLSUIElementValue:(BOOL)arg1;
- (void)restartApp;
- (void)setCustomAppIconToFileAtPath:(id)arg1;
- (void)generateIcnsFile:(id)arg1;
- (void)menuExtraStatusChanged;
- (void)embeddedStatusChanged;
- (void)touchApp;
- (void)touchFileAtPath:(id)arg1;
- (id)statusItemMenu;
- (void)unhighlightStatusItem;
- (void)statusMenuItemShowPreferencesPanel:(id)arg1;
- (void)statusMenuItemTerminate:(id)arg1;
- (void)checkLSUIElementValueIsConsistentWithMenuExtraStatus;
- (void)setupStatusItem;
- (struct _NSRect)frameForStatusItemWindow;
- (void)orderOutStatusItemWindow:(id)arg1;
- (void)showStatusItemMenu:(id)arg1;
- (void)hideStatusItemMenu:(id)arg1;
- (void)statusItemActivated:(id)arg1;
- (void)showHiddenBrowserWindowIfExists;
- (void)setDockTileImageView:(id)arg1;
- (id)dockTileImageView;
- (id)recorderControlAutosaveName;
- (void)hitHotKey:(id)arg1;
- (void)setupGlobalHotKey;
- (id)fullScreenScreen;
- (void)setFullScreenScreen:(id)arg1;
- (BOOL)hasHiddenWindow;
- (void)setHasHiddenWindow:(BOOL)arg1;
- (id)bookmarks;
- (void)setBookmarks:(id)arg1;
- (id)historyMenuObjects;
- (void)setHistoryMenuObjects:(id)arg1;
- (id)plugInDirPath;
- (void)setPlugInDirPath:(id)arg1;
- (id)plugInPrivateDirPath;
- (void)setPlugInPrivateDirPath:(id)arg1;
- (id)downloadArchiveFilePath;
- (void)setDownloadArchiveFilePath:(id)arg1;
- (id)bookmarksFilePath;
- (void)setBookmarksFilePath:(id)arg1;
- (id)webHistoryFilePath;
- (void)setWebHistoryFilePath:(id)arg1;
- (id)userstyleFilePath;
- (void)setUserstyleFilePath:(id)arg1;
- (id)userstyleDirPath;
- (void)setUserstyleDirPath:(id)arg1;
- (id)userscriptDirPath;
- (void)setUserscriptDirPath:(id)arg1;
- (id)ssbSupportDirPath;
- (void)setSsbSupportDirPath:(id)arg1;
- (id)appSupportDirPath;
- (void)setAppSupportDirPath:(id)arg1;
- (id)googleAppsDomain;
- (void)setGoogleAppsDomain:(id)arg1;
- (BOOL)isMobileMe;
- (void)setIsMobileMe:(BOOL)arg1;
- (BOOL)isFlickr;
- (void)setIsFlickr:(BOOL)arg1;
- (BOOL)isFacebook;
- (void)setIsFacebook:(BOOL)arg1;
- (BOOL)isYahooMail;
- (void)setIsYahooMail:(BOOL)arg1;
- (BOOL)isGoogleReader;
- (void)setIsGoogleReader:(BOOL)arg1;
- (BOOL)isGoogleApps;
- (void)setIsGoogleApps:(BOOL)arg1;
- (BOOL)isGmail;
- (void)setIsGmail:(BOOL)arg1;
- (BOOL)isFullScreen;
- (void)setFullScreen:(BOOL)arg1;
- (id)specialCases;
- (void)setSpecialCases:(id)arg1;
- (id)appName;
- (void)setAppName:(id)arg1;
- (id)defaultUserAgentFormat;
- (void)setDefaultUserAgentFormat:(id)arg1;
- (void)setDefaultUserAgentString:(id)arg1;
- (id)userAgentStrings;
- (void)setUserAgentStrings:(id)arg1;
- (id)originalHomeURLString;
- (void)setOriginalHomeURLString:(id)arg1;
- (id)homeURLString;
- (void)setHomeURLString:(id)arg1;
- (id)homeURL;
- (void)setHomeURL:(id)arg1;
- (float)statusItemWindowFrameX;
- (void)setStatusItemWindowFrameX:(float)arg1;
- (BOOL)statusItemMenuVisible;
- (void)setStatusItemMenuVisible:(BOOL)arg1;
- (BOOL)statusItemVisible;
- (void)setStatusItemVisible:(BOOL)arg1;
- (void)setStatusItemMenu:(id)arg1;
- (id)statusItemWindow;
- (void)setStatusItemWindow:(id)arg1;
- (id)statusItem;
- (void)setStatusItem:(id)arg1;

@end

@interface TODBrowserWindowController : NSWindowController <TODTinyURLResolverDelegate>
{
    TODBrowserProgressComboBox *locationComboBox;
    NSSplitView *locationSplitView;
    NSSearchField *searchField;
    NSProgressIndicator *progressIndicator;
    NSView *tabContentContainer;
    NSTabView *tabView;
    PSMTabBarControl *tabBar;
    TODBookmarkBar *bookmarkBar;
    NSView *statusBar;
    TODUberView *uberView;
    NSMenu *searchMenu;
    NSView *findPanelView;
    NSSearchField *findPanelSearchField;
    BOOL typingInFindPanel;
    NSWindow *JSAlertSheet;
    NSWindow *JSConfirmSheet;
    NSString *JSAlertText;
    BOOL themed;
    NSMutableArray *webViews;
    WebView *webView;
    NSString *currentTitle;
    NSString *statusText;
    NSDictionary *lastClickedElementInfo;
    NSDictionary *lastMouseOverElementInfo;
    BOOL hasRSSLink;
    BOOL suppressPlugIns;
    BOOL displayingMatchingRecentURLs;
    BOOL lastLoadFailed;
    BOOL windowFullyLoaded;
    BOOL userRequestedClose;
    TODViewSourceWindowController *sourceController;
    TODTinyURLResolver *resolver;
    NSMutableDictionary *anchorsForTinyURLs;
    double progress;
    NSMutableDictionary *userscriptSourceIdsForWebViews;
    NSMutableDictionary *userscriptSourceIdStacksForWebViews;
    BOOL shouldClose;
    NSColor *statusTextColor;
    TODShortcutController *commandURLCompiler;
    NSString *searchTerm;
}

- (id)initWithWindowNibName:(id)arg1;
- (void)dealloc;
- (void)awakeFromNib;
- (void)windowDidLoad;
- (void)showVisiblePlugIns;
- (id)windowTitleForDocumentDisplayName:(id)arg1;
- (void)goToLocation:(id)arg1;
- (void)openLocation:(id)arg1;
- (void)doGoBack:(id)arg1;
- (void)doGoForward:(id)arg1;
- (void)makeTextLarger:(id)arg1;
- (void)makeTextSmaller:(id)arg1;
- (void)toggleToolbarShown:(id)arg1;
- (void)doReload:(id)arg1;
- (void)stopLoading:(id)arg1;
- (void)goHome:(id)arg1;
- (void)viewSource:(id)arg1;
- (void)emptyCache:(id)arg1;
- (void)search:(id)arg1;
- (void)openSearch:(int)arg1;
- (void)openNeutralSearch:(id)arg1;
- (void)openGoogleSiteSearch:(id)arg1;
- (void)openGoogleSearch:(id)arg1;
- (void)openBOSSSearch:(id)arg1;
- (void)openYubnubCommand:(id)arg1;
- (void)addBookmark:(id)arg1;
- (void)mailLink:(id)arg1;
- (void)postNotificationForNewTab:(id)arg1;
- (void)addNewTab:(id)arg1;
- (void)addNewTabInBackground:(id)arg1;
- (void)closeTab:(id)arg1;
- (void)performClose:(id)arg1;
- (void)selectNextTab:(id)arg1;
- (void)selectPreviousTab:(id)arg1;
- (void)displayFeeds:(id)arg1;
- (void)feedSelected:(id)arg1;
- (void)handleSelectedFeed:(id)arg1;
- (void)bookmarkClicked:(id)arg1;
- (void)makeTinyURL:(id)arg1;
- (void)downForEveryoneOrJustMe:(id)arg1;
- (void)resetToPreferredSplitPositions:(id)arg1;
- (BOOL)isFindPanelVisible;
- (void)hideFindPanelAction:(id)arg1;
- (void)showFindPanelAction:(id)arg1;
- (void)toggleFindPanel:(BOOL)arg1;
- (BOOL)findPanelSearchField:(id)arg1 textShouldEndEditing:(id)arg2;
- (void)findPanelSearchFieldDidBeginEditing:(id)arg1;
- (void)controlTextDidChange:(id)arg1;
- (void)controlTextDidEndEditing:(id)arg1;
- (void)find:(id)arg1;
- (void)useSelectionForFind:(id)arg1;
- (void)jumpToSelection:(id)arg1;
- (void)downForEveryoneOrJustMeForURL:(id)arg1;
- (BOOL)tryToResolveTinyURLForElementInfo:(id)arg1;
- (void)tinyURLResolver:(id)arg1 didResolveURLString:(id)arg2 fromTinyURLString:(id)arg3;
- (void)tinyURLResolver:(id)arg1 failedToResolveTinyURLString:(id)arg2;
- (BOOL)validateMenuItem:(id)arg1;
- (void)tabView:(id)arg1 willSelectTabViewItem:(id)arg2;
- (void)tabView:(id)arg1 didSelectTabViewItem:(id)arg2;
- (BOOL)tabView:(id)arg1 shouldCloseTabViewItem:(id)arg2;
- (void)tabView:(id)arg1 willCloseTabViewItem:(id)arg2;
- (void)tabView:(id)arg1 didCloseTabViewItem:(id)arg2;
- (void)postNotificationForClosedTab:(id)arg1;
- (BOOL)hmComboBox:(id)arg1 writeDataToPasteboard:(id)arg2;
- (void)controlTextDidBeginEditing:(id)arg1;
- (BOOL)control:(id)arg1 textShouldBeginEditing:(id)arg2;
- (BOOL)control:(id)arg1 textShouldEndEditing:(id)arg2;
- (void)comboBoxWillDismiss:(id)arg1;
- (id)comboBox:(id)arg1 objectValueForItemAtIndex:(int)arg2;
- (int)numberOfItemsInComboBox:(id)arg1;
- (int)comboBox:(id)arg1 indexOfItemWithStringValue:(id)arg2;
- (id)comboBox:(id)arg1 completedString:(id)arg2;
- (id)control:(id)arg1 textView:(id)arg2 completions:(id)arg3 forPartialWordRange:(struct _NSRange)arg4 indexOfSelectedItem:(int *)arg5;
- (void)splitView:(id)arg1 resizeSubviewsWithOldSize:(struct _NSSize)arg2;
- (BOOL)splitView:(id)arg1 shouldCollapseSubview:(id)arg2 forDoubleClickOnDividerAtIndex:(int)arg3;
- (BOOL)splitView:(id)arg1 canCollapseSubview:(id)arg2;
- (float)splitView:(id)arg1 constrainMinCoordinate:(float)arg2 ofSubviewAt:(int)arg3;
- (float)splitView:(id)arg1 constrainMaxCoordinate:(float)arg2 ofSubviewAt:(int)arg3;
- (void)windowDidResignKey:(id)arg1;
- (BOOL)windowShouldCloseIgnoringHiddenWindowIfExists:(id)arg1;
- (BOOL)windowShouldClose:(id)arg1;
- (void)windowWillClose:(id)arg1;
- (void)webViewProgressStarted:(id)arg1;
- (void)webViewProgressEstimateChanged:(id)arg1;
- (void)webViewProgressFinished:(id)arg1;
- (void)tinyURLResolver:(id)arg1 didResolveURLString:(id)arg2;
- (void)tinyURLResolverFailed:(id)arg1;
- (id)TODBrowserDocument;
- (void)setWindowFrame;
- (void)setupTabView;
- (void)configureTabControlBar;
- (void)configureWebView:(id)arg1;
- (void)setupLocationSplitView;
- (void)setupWebPreferencesForWebView:(id)arg1;
- (void)registerForNotifications;
- (void)registerForWebViewProgressNotificationsFromWebView:(id)arg1;
- (void)unregisterForWebViewProgressNotificationsFromWebView:(id)arg1;
- (void)unregisterForNotifications;
- (void)unbindCurrentTabTitle;
- (BOOL)URLStringStartsWithSupportedScheme:(id)arg1;
- (BOOL)URLStringStartsWithHTTPScheme:(id)arg1;
- (void)removeDocumentIconButton;
- (BOOL)displayingMatchingRecentURLs;
- (id)recentURLs;
- (id)matchingRecentURLs;
- (void)searchEntireWebChanged:(id)arg1;
- (void)bookmarkBarShownChanged:(id)arg1;
- (void)tabBarShownChanged:(id)arg1;
- (void)statusBarShownChanged:(id)arg1;
- (void)doMakeTinyURL:(id)arg1;
- (void)spacesBehaviorChanged:(id)arg1;
- (void)windowLevelChanged:(id)arg1;
- (void)windowOpacityChanged:(id)arg1;
- (void)windowsHaveShadowChanged:(id)arg1;
- (void)chromeOpacityChanged:(id)arg1;
- (void)windowsDraggableFromAnywhereChanged:(id)arg1;
- (void)configureDraggableBehaviorinWebView:(id)arg1;
- (int)indexOfSelectedTab;
- (void)selectTabAtIndex:(int)arg1;
- (void)addRecentURL:(id)arg1;
- (void)addMatchingRecentURL:(id)arg1;
- (void)displayEstimatedProgress;
- (void)handleCommandClick:(int)arg1 request:(id)arg2;
- (void)handlePopUpUnderFullScreenMode:(int)arg1 request:(id)arg2;
- (BOOL)isMiddleButtonClick:(id)arg1;
- (int)modifierFlagsForAction:(id)arg1;
- (BOOL)wasCommandKeyPressed:(int)arg1;
- (BOOL)wasShiftKeyPressed:(int)arg1;
- (BOOL)wasOptionKeyPressed:(int)arg1;
- (void)alterMobileMeHeader:(id)arg1;
- (void)setStatusText:(id)arg1;
- (BOOL)typingInFindPanel;
- (void)setTypingInFindPanel:(BOOL)arg1;
- (id)searchTerm;
- (void)setSearchTerm:(id)arg1;
- (id)sourceController;
- (void)setSourceController:(id)arg1;
- (BOOL)userRequestedClose;
- (void)setUserRequestedClose:(BOOL)arg1;
- (BOOL)suppressPlugIns;
- (void)setSuppressPlugIns:(BOOL)arg1;
- (id)commandURLCompiler;
- (void)setCommandURLCompiler:(id)arg1;
- (id)JSAlertText;
- (void)setJSAlertText:(id)arg1;
- (id)anchorsForTinyURLs;
- (void)setAnchorsForTinyURLs:(id)arg1;
- (id)resolver;
- (void)setResolver:(id)arg1;
- (id)statusTextColor;
- (void)setStatusTextColor:(id)arg1;
- (BOOL)isWindowFullyLoaded;
- (void)setWindowFullyLoaded:(BOOL)arg1;
- (BOOL)lastLoadFailed;
- (void)setLastLoadFailed:(BOOL)arg1;
- (BOOL)shouldClose;
- (void)setShouldClose:(BOOL)arg1;
- (id)userscriptSourceIdStacksForWebViews;
- (void)setUserscriptSourceIdStacksForWebViews:(id)arg1;
- (id)userscriptSourceIdsForWebViews;
- (void)setUserscriptSourceIdsForWebViews:(id)arg1;
- (BOOL)hasRSSLink;
- (void)setHasRSSLink:(BOOL)arg1;
- (double)progress;
- (void)setProgress:(double)arg1;
- (id)lastMouseOverElementInfo;
- (void)setLastMouseOverElementInfo:(id)arg1;
- (id)lastClickedElementInfo;
- (void)setLastClickedElementInfo:(id)arg1;
- (id)statusText;
- (id)currentTitle;
- (void)setCurrentTitle:(id)arg1;
- (id)uberView;
- (void)setUberView:(id)arg1;
- (id)webView;
- (void)setWebView:(id)arg1;
- (id)webViews;
- (void)setWebViews:(id)arg1;
- (id)statusBar;
- (void)setStatusBar:(id)arg1;
- (id)bookmarkBar;
- (void)setBookmarkBar:(id)arg1;
- (id)tabBar;
- (void)setTabBar:(id)arg1;
- (id)tabView;
- (void)setTabView:(id)arg1;
- (BOOL)isThemed;
- (void)setThemed:(BOOL)arg1;

@end

@interface TODBrowserDocument : NSDocument
{
    TODBrowserWindowController *controller;
    WebArchive *webArchive;
    NSString *initialURLString;
}

+ (void)initialize;
- (id)init;
- (id)initWithContentsOfURL:(id)arg1 ofType:(id)arg2 error:(id *)arg3;
- (id)initForURL:(id)arg1 withContentsOfURL:(id)arg2 ofType:(id)arg3 error:(id *)arg4;
- (void)dealloc;
- (void)makeWindowControllers;
- (BOOL)isDocumentEdited;
- (BOOL)readFromURL:(id)arg1 ofType:(id)arg2 error:(id *)arg3;
- (BOOL)writeToURL:(id)arg1 ofType:(id)arg2 error:(id *)arg3;
- (void)printDocumentWithSettings:(id)arg1 showPrintPanel:(BOOL)arg2 delegate:(id)arg3 didPrintSelector:(SEL)arg4 contextInfo:(void *)arg5;
- (void)_printOperationDidRun:(id)arg1 success:(BOOL)arg2 contextInfo:(void *)arg3;
- (id)webView;
- (id)initialURLString;
- (void)setInitialURLString:(id)arg1;
- (id)webArchive;
- (void)setWebArchive:(id)arg1;

@end

@interface TODDownloadWindowController : NSWindowController
{
    NSCollectionView *collectionView;
    NSScrollView *scrollView;
    NSArrayController *arrayController;
    NSView *statusBar;
    NSMutableArray *downloadItems;
    NSMutableDictionary *indexForURLDownloadTable;
    unsigned int numberOfDownloadItems;
}

+ (id)instance;
- (id)initWithWindowNibName:(id)arg1;
- (void)dealloc;
- (void)awakeFromNib;
- (void)showWindow:(id)arg1;
- (void)stopDownload:(id)arg1;
- (void)resumeDownload:(id)arg1;
- (void)revealDownloadInFinder:(id)arg1;
- (void)clearDownloads:(id)arg1;
- (void)windowDidBecomeKey:(id)arg1;
- (void)windowDidResignKey:(id)arg1;
- (void)windowDidBecomeMain:(id)arg1;
- (void)windowDidResignMain:(id)arg1;
- (void)insertDownloadItem:(id)arg1;
- (id)downloadItemForURLDownload:(id)arg1;
- (unsigned int)indexForButton:(id)arg1;
- (id)downloadItemForButton:(id)arg1;
- (void)scrollToBottom;
- (id)downloadWindowForAuthenticationSheet:(id)arg1;
- (void)downloadDidBegin:(id)arg1;
- (id)download:(id)arg1 willSendRequest:(id)arg2 redirectResponse:(id)arg3;
- (void)download:(id)arg1 didReceiveResponse:(id)arg2;
- (void)download:(id)arg1 willResumeWithResponse:(id)arg2 fromByte:(long long)arg3;
- (void)download:(id)arg1 didReceiveDataOfLength:(unsigned int)arg2;
- (BOOL)download:(id)arg1 shouldDecodeSourceDataOfMIMEType:(id)arg2;
- (void)download:(id)arg1 decideDestinationWithSuggestedFilename:(id)arg2;
- (void)downloadDidFinish:(id)arg1;
- (void)download:(id)arg1 didFailWithError:(id)arg2;
- (unsigned int)numberOfDownloadItems;
- (void)setNumberOfDownloadItems:(unsigned int)arg1;
- (id)indexForURLDownloadTable;
- (void)setIndexForURLDownloadTable:(id)arg1;
- (id)downloadItems;
- (void)setDownloadItems:(id)arg1;
- (id)statusBar;
- (void)setStatusBar:(id)arg1;

@end

@interface TODDownloadItem : NSObject <NSCoding>
{
    NSDate *startDate;
    NSDate *lastDisplayDate;
    NSURL *URL;
    NSURLDownload *download;
    NSString *filename;
    NSString *path;
    NSImage *icon;
    NSString *status;
    NSString *remainingTimeString;
    unsigned int expectedLength;
    unsigned int receivedLength;
    float ratio;
    BOOL isUserscript;
    BOOL busy;
    BOOL done;
    BOOL canResume;
}

- (id)initWithURLDownload:(id)arg1;
- (void)dealloc;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (id)description;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (void)determineRemainingTimeString;
- (void)lengthDidChange;
- (BOOL)canResume;
- (void)setCanResume:(BOOL)arg1;
- (BOOL)done;
- (void)setDone:(BOOL)arg1;
- (BOOL)busy;
- (void)setBusy:(BOOL)arg1;
- (BOOL)isUserscript;
- (void)setIsUserscript:(BOOL)arg1;
- (float)ratio;
- (void)setRatio:(float)arg1;
- (unsigned int)receivedLength;
- (void)setReceivedLength:(unsigned int)arg1;
- (unsigned int)expectedLength;
- (void)setExpectedLength:(unsigned int)arg1;
- (id)icon;
- (void)setIcon:(id)arg1;
- (id)status;
- (void)setStatus:(id)arg1;
- (id)remainingTimeString;
- (void)setRemainingTimeString:(id)arg1;
- (id)path;
- (void)setPath:(id)arg1;
- (id)filename;
- (void)setFilename:(id)arg1;
- (id)download;
- (void)setDownload:(id)arg1;
- (id)URL;
- (void)setURL:(id)arg1;
- (id)lastDisplayDate;
- (void)setLastDisplayDate:(id)arg1;
- (id)startDate;
- (void)setStartDate:(id)arg1;

@end

@interface TODViewSourceWindowController : NSWindowController
{
    TDSourceCodeTextView *sourceTextView;
    NSString *location;
    NSAttributedString *source;
    NSFont *monacoFont;
    float sourceTextViewOffset;
    TDHtmlSyntaxHighlighter *highlighter;
    int tag;
}

- (id)init;
- (void)dealloc;
- (void)showWindow:(id)arg1;
- (void)addNewTab:(id)arg1;
- (void)runFontPanel:(id)arg1;
- (void)showFindPanelAction:(id)arg1;
- (void)find:(id)arg1;
- (void)useSelectionForFind:(id)arg1;
- (void)displaySourceString:(id)arg1;
- (int)tag;
- (void)setTag:(int)arg1;
- (id)highlighter;
- (void)setHighlighter:(id)arg1;
- (id)source;
- (void)setSource:(id)arg1;
- (id)location;
- (void)setLocation:(id)arg1;
- (id)monacoFont;
- (void)setMonacoFont:(id)arg1;

@end

@interface TODBookmarkWindowController : NSWindowController
{
    NSTableView *bookmarksTableView;
    NSArrayController *arrayController;
    NSMutableArray *bookmarks;
}

+ (id)instance;
- (id)initWithWindowNibName:(id)arg1;
- (void)dealloc;
- (void)showWindow:(id)arg1;
- (void)insert:(id)arg1;
- (void)remove:(id)arg1;
- (void)notifyBookmarksChanged;
- (void)windowDidBecomeKey:(id)arg1;
- (void)update;
- (void)windowDidResignKey:(id)arg1;
- (void)insertObject:(id)arg1 inBookmarksAtIndex:(int)arg2;
- (void)removeObjectFromBookmarksAtIndex:(int)arg1;
- (void)startObservingBookmark:(id)arg1;
- (void)stopObservingBookmark:(id)arg1;
- (void)changeKeyPath:(id)arg1 ofObject:(id)arg2 toValue:(id)arg3;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (id)bookmarks;
- (void)setBookmarks:(id)arg1;

@end

@interface TODRecentURLManager : NSObject
{
    NSMutableArray *recentURLs;
    NSMutableArray *matchingRecentURLs;
}

+ (void)initialize;
+ (void)createInstance;
+ (id)instance;
- (id)init;
- (void)dealloc;
- (void)renewRecentURLs;
- (void)renewMatchingRecentURLs;
- (void)addRecentURL:(id)arg1;
- (void)addBaseURLForURLString:(id)arg1;
- (void)checkForOverTheLimit;
- (void)removeRecentURL:(id)arg1;
- (void)addMatchingRecentURL:(id)arg1;
- (id)matchingRecentURLs;
- (void)setMatchingRecentURLs:(id)arg1;
- (id)recentURLs;
- (void)setRecentURLs:(id)arg1;

@end

@interface TODBrowserWindow : NSWindow
{
    TODBookmarkBar *bookmarkBar;
    BOOL mouseInRegion;
    BOOL themed;
    BOOL shouldIgnoreNextResize;
    TODThemeFrame *todThemeFrame;
}

+ (Class)frameViewClassForStyleMask:(unsigned int)arg1;
+ (id)mainContentFill;
+ (id)nonMainContentFill;
+ (id)titlebarFill;
+ (id)statusbarFill;
- (id)initWithContentRect:(struct _NSRect)arg1 styleMask:(unsigned int)arg2 backing:(unsigned int)arg3 defer:(BOOL)arg4;
- (void)dealloc;
- (void)awakeFromNib;
- (void)becomeMainWindow;
- (void)resignMainWindow;
- (void)becomeKeyWindow;
- (void)resignKeyWindow;
- (void)toggleToolbarShown:(id)arg1;
- (float)titlebarHeight;
- (float)toolbarHeight;
- (void)mouseMoved:(id)arg1;
- (void)sendMouseMovedEvent:(id)arg1 toPlugInWithIdentifier:(id)arg2;
- (void)performClose:(id)arg1;
- (void)doPerformClose:(id)arg1;
- (void)forceClose;
- (void)close;
- (void)setFrame:(struct _NSRect)arg1 display:(BOOL)arg2;
- (BOOL)isMovableByWindowBackground;
- (BOOL)validateMenuItem:(id)arg1;
- (void)moveWindow:(id)arg1;
- (BOOL)makeFirstResponder:(id)arg1;
- (void)sendEvent:(id)arg1;
- (BOOL)shouldIgnoreNextResize;
- (void)setShouldIgnoreNextResize:(BOOL)arg1;
- (id)todThemeFrame;
- (void)setTodThemeFrame:(id)arg1;
- (BOOL)isThemed;
- (void)setThemed:(BOOL)arg1;

@end

@interface TODBrowserToolbar : NSToolbar
{
}

- (unsigned int)displayMode;
- (unsigned int)sizeMode;
- (void)setDisplayMode:(unsigned int)arg1;
- (void)setSizeMode:(unsigned int)arg1;
- (BOOL)showsBaselineSeparator;

@end

@interface TODBrowserProgressComboBox : HMImageComboBox
{
    NSImage *progressImage;
    float progress;
    BOOL showingPopUp;
    BOOL firstDownKeyStrokeHasHappened;
}

- (void)dealloc;
- (void)awakeFromNib;
- (BOOL)acceptsFirstMouse:(id)arg1;
- (BOOL)shouldDelayWindowOrderingForEvent:(id)arg1;
- (void)drawRect:(struct _NSRect)arg1;
- (void)setProgress:(float)arg1;
- (void)showDefaultIcon;
- (void)showPopUpWithItemCount:(int)arg1;
- (void)hidePopUp;
- (void)keyUp:(id)arg1;
- (id)progressImage;
- (void)setProgressImage:(id)arg1;
- (float)progress;

@end

@interface TODTabModel : NSObject
{
    BOOL isProcessing;
    NSString *iconName;
    NSObjectController *controller;
}

- (id)init;
- (void)dealloc;
- (id)controller;
- (void)setController:(id)arg1;
- (id)iconName;
- (void)setIconName:(id)arg1;
- (BOOL)isProcessing;
- (void)setIsProcessing:(BOOL)arg1;

@end

@interface TODJavaScriptFluidObject : NSObject
{
    WebScriptObject *windowScriptObject;
    BOOL privilegedAccessAllowed;
    id dockBadge;
    NSMutableArray *menuItems;
    WebScriptObject *onclick;
    NSString *applicationPath;
    NSString *resourcePath;
    NSString *userscriptPath;
}

+ (id)webScriptNameForKey:(const char *)arg1;
+ (id)webScriptNameForSelector:(SEL)arg1;
+ (BOOL)isKeyExcludedFromWebScript:(const char *)arg1;
+ (BOOL)isSelectorExcludedFromWebScript:(SEL)arg1;
- (id)initWithWindowScriptObject:(id)arg1;
- (void)dealloc;
- (id)description;
- (void)setDockBadgeMethod:(id)arg1;
- (void)showGrowlNotification:(id)arg1;
- (void)addDockMenuItemWithTitle:(id)arg1 function:(id)arg2;
- (void)removeDockMenuItemWithTitle:(id)arg1;
- (void)menuItemClick:(id)arg1;
- (void)beep;
- (void)playSoundNamed:(id)arg1;
- (id)dockBadge;
- (void)setDockBadge:(id)arg1;
- (id)applicationPath;
- (id)resourcePath;
- (id)userscriptPath;
- (void)attachToFileUpload:(id)arg1;
- (void)log:(id)arg1;
- (void)activate;
- (void)terminate;
- (void)hide;
- (void)unhide;
- (void)import:(id)arg1;
- (id)toString:(id)arg1;
- (id)onclick;
- (void)setOnclick:(id)arg1;
- (id)menuItems;
- (void)setMenuItems:(id)arg1;
- (id)windowScriptObject;
- (void)setWindowScriptObject:(id)arg1;
- (BOOL)isPrivilegedAccessAllowed;
- (void)setPrivilegedAccessAllowed:(BOOL)arg1;

@end

@interface TODBookmarkBar : NSView
{
    TODBookmarkButtonSeparator *separator;
    NSMutableArray *buttons;
    int currDropIndex;
    TODBookmarkBarOverflowButton *overflowButton;
    NSMenu *overflowMenu;
    int visibleButtonCount;
    TODBookmarkBarButton *draggingButton;
}

- (id)nonMainBackgroundColor;
- (id)mainBackgroundColor;
- (id)initWithFrame:(struct _NSRect)arg1;
- (void)dealloc;
- (void)drawRect:(struct _NSRect)arg1;
- (void)awakeFromNib;
- (void)otherMouseDown:(id)arg1;
- (void)addItem:(id)arg1;
- (void)addButtonForItem:(id)arg1;
- (void)startedDraggingButton:(id)arg1;
- (void)draggingExited:(id)arg1;
- (unsigned int)draggingUpdated:(id)arg1;
- (unsigned int)draggingEntered:(id)arg1;
- (BOOL)performDragOperation:(id)arg1;
- (void)concludeDragOperation:(id)arg1;
- (id)createButtonWithItem:(id)arg1;
- (void)performActionForButton:(id)arg1;
- (void)updateSeparatorForPoint:(struct _NSPoint)arg1;
- (id)buttonAtX:(float)arg1;
- (void)resizeSubviewsWithOldSize:(struct _NSSize)arg1;
- (void)addItem:(id)arg1 atIndex:(int)arg2;
- (void)addButtonForItem:(id)arg1 atIndex:(int)arg2;
- (void)layoutButtons;
- (void)createOverflowMenu;
- (void)bookmarksChanged:(id)arg1;
- (void)removeAllButtons;
- (void)registerForNotifications;
- (void)notifyBookmarksChanged;
- (id)draggingButton;
- (void)setDraggingButton:(id)arg1;
- (id)overflowMenu;
- (void)setOverflowMenu:(id)arg1;
- (id)overflowButton;
- (void)setOverflowButton:(id)arg1;
- (id)buttons;
- (void)setButtons:(id)arg1;
- (id)separator;
- (void)setSeparator:(id)arg1;

@end

@interface TODBookmarkBarButton : HMButton
{
    TODBookmarkBar *bookmarkBar;
    TODBookmark *item;
    BOOL hovered;
}

+ (Class)cellClass;
- (id)initWithBookmarkBar:(id)arg1 item:(id)arg2;
- (void)dealloc;
- (void)mouseDown:(id)arg1;
- (void)mouseDragged:(id)arg1;
- (unsigned int)draggingSourceOperationMaskForLocal:(BOOL)arg1;
- (void)draggedImage:(id)arg1 endedAt:(struct _NSPoint)arg2 operation:(unsigned int)arg3;
- (id)item;
- (void)setItem:(id)arg1;
- (id)bookmarkBar;
- (void)setBookmarkBar:(id)arg1;
- (BOOL)isHovered;
- (void)setHovered:(BOOL)arg1;

@end

@interface TODBookmarkBarOverflowButton : NSButton
{
    NSTimer *timer;
}

+ (id)bundle;
- (id)init;
- (void)dealloc;
- (void)displayMenu:(id)arg1;
- (void)mouseDown:(id)arg1;
- (void)mouseUp:(id)arg1;
- (void)unhighlight;
- (id)imageNamed:(id)arg1;
- (id)timer;
- (void)setTimer:(id)arg1;

@end

@interface TODBookmarkButtonSeparator : NSView
{
}

- (id)init;
- (void)drawRect:(struct _NSRect)arg1;

@end

@interface TODBookmark : NSObject <NSCoding>
{
    NSString *title;
    NSString *content;
}

- (id)init;
- (void)dealloc;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)description;
- (id)content;
- (void)setContent:(id)arg1;
- (id)title;
- (void)setTitle:(id)arg1;

@end

@interface TODSecurityPreferences : TODAbstractBasePreferences
{
}

- (void)toggleArePluginsEnabled:(id)arg1;
- (void)toggleIsJavaEnabled:(id)arg1;
- (void)toggleIsJavaScriptEnabled:(id)arg1;
- (void)toggleBlockPopUpWindows:(id)arg1;
- (void)changeCookieAcceptPolicy:(id)arg1;

@end

@interface TODGeneralPreferences : TODAbstractBasePreferences
{
    SRRecorderControl *recorderControl;
    AMPathPopUpButton *downloadFolderPopUpButton;
    PTHotKey *globalHotKey;
    BOOL busy;
}

- (void)dealloc;
- (void)awakeFromNib;
- (void)shortcutRecorderCell:(id)arg1 keyComboDidChange:(struct _KeyCombo)arg2;
- (id)recorderControlAutosaveName;
- (void)toggleGlobalHotKey:(id)arg1;
- (void)changeAppIcon:(id)arg1;
- (void)doChangeAppIcon;
- (void)downloadFolderChanged:(id)arg1;
- (id)globalHotKey;
- (void)setGlobalHotKey:(id)arg1;
- (BOOL)isBusy;
- (void)setBusy:(BOOL)arg1;

@end

@interface TODTabsPreferences : TODAbstractBasePreferences
{
}

- (void)updateUI;
- (void)setValueForSender:(id)arg1;

@end

@interface TODAppearancePreferences : TODAbstractBasePreferences
{
    NSTextField *standardFontTextField;
    NSTextField *fixedWidthFontTextField;
    BOOL selectingStandard;
}

- (void)dealloc;
- (void)updateUI;
- (id)standardFontDisplayString;
- (id)fixedWidthFontDisplayString;
- (void)runFontPanel:(id)arg1;
- (id)standardFont;
- (id)fixedWidthFont;
- (void)changeFont:(id)arg1;
- (void)spacesBehaviorChange:(id)arg1;
- (void)windowLevelChange:(id)arg1;
- (void)windowOpacityChange:(id)arg1;
- (void)chromeOpacityChange:(id)arg1;
- (void)windowsDraggableFromAnyhwereChange:(id)arg1;
- (void)windowsHaveShadowChange:(id)arg1;
- (void)toggleSetLoadsImagesAutomatically:(id)arg1;
- (BOOL)spacesBehaviorEnabled;
- (BOOL)windowStylesEnabled;
- (BOOL)windowLevelsEnabled;
- (BOOL)windowsDraggableFromAnywhereEnabled;

@end

@interface TODUpdatePreferences : TODAbstractBasePreferences
{
}

- (void)checkForUpdates:(id)arg1;

@end

@interface TODApplication : OAApplication
{
    SUUpdater *updater;
}

- (void)dealloc;
- (void)showPreferencesPanel:(id)arg1;
- (id)updater;
- (void)changeFont:(id)arg1;

@end

@interface TODPlugInPreferences : TODAbstractBasePreferences
{
    NSView *contentView;
    NSPopUpButton *viewPlacementPopUpButton;
    TODBrowserPlugInWrapper *plugInWrapper;
}

- (id)init;
- (void)dealloc;
- (void)updatePopUpMenu;
- (id)contentView;
- (id)viewPlacementPopUpButton;
- (void)viewPlacementMenuItemAction:(id)arg1;
- (void)changeFont:(id)arg1;
- (BOOL)validateMenuItem:(id)arg1;
- (void)valuesHaveChanged;
- (id)plugInWrapper;
- (void)setPlugInWrapper:(id)arg1;

@end

@interface TODWebImageBrowserItem : NSObject
{
    NSURL *URL;
    NSImage *image;
    NSString *absoluteURLString;
    NSString *title;
    NSString *subtitle;
}

+ (id)itemWithImage:(id)arg1 URL:(id)arg2;
- (id)initWithImage:(id)arg1 URL:(id)arg2;
- (void)dealloc;
- (id)imageUID;
- (id)imageRepresentationType;
- (id)imageRepresentation;
- (id)imageTitle;
- (id)imageSubtitle;
- (BOOL)isSelectable;
- (id)subtitle;
- (void)setSubtitle:(id)arg1;
- (id)title;
- (void)setTitle:(id)arg1;
- (id)absoluteURLString;
- (void)setAbsoluteURLString:(id)arg1;
- (id)URL;
- (void)setURL:(id)arg1;
- (id)image;
- (void)setImage:(id)arg1;

@end

@interface TODBrowserPlugInControllerImpl : NSObject <TODBrowserPlugInController>
{
    NSString *version;
    NSString *plugInSupportDirPath;
}

- (id)init;
- (void)dealloc;
- (id)mainWebView;
- (id)webViews;
- (void)loadRequest:(id)arg1 inNewTabInBackground:(BOOL)arg2;
- (void)loadRequest:(id)arg1 inNewWindowInBackground:(BOOL)arg2;
- (void)showStatusText:(id)arg1;
- (void)registerForUserscriptExecutionInWebView:(id)arg1;
- (void)unregisterForUserscriptExecutionInWebView:(id)arg1;
- (id)plugInSupportDirPath;
- (void)setPlugInSupportDirPath:(id)arg1;
- (id)version;
- (void)setVersion:(id)arg1;

@end

@interface TODUserscriptWindowController : NSWindowController
{
    NSString *filename;
}

+ (id)instance;
- (id)initWithWindowNibName:(id)arg1;
- (void)dealloc;
- (void)showWindow:(id)arg1;
- (void)create:(id)arg1;
- (void)cancel:(id)arg1;
- (id)filename;
- (void)setFilename:(id)arg1;

@end

@interface TODBrowserPlugInManager : NSObject
{
    NSMenu *plugInMenu;
    NSMutableDictionary *windowsForPlugInIdentifier;
    id <TODBrowserPlugInController> plugInController;
    NSMutableArray *plugInWrappers;
    NSMutableArray *allPlugInIdentifiers;
    BOOL plugInsLoaded;
}

+ (void)initialize;
+ (id)instance;
+ (BOOL)isSplitViewPlacementMask:(int)arg1;
- (id)init;
- (void)dealloc;
- (void)loadPlugIns;
- (void)loadPlugInsAtPath:(id)arg1;
- (void)loadPlugInAtPath:(id)arg1;
- (void)loadPlugIn:(id)arg1;
- (void)createMenuItemsForPlugIns;
- (void)registerNotificationsOnPlugInWrapper:(id)arg1;
- (BOOL)validateMenuItem:(id)arg1;
- (void)createMenuItemsForPlugInWrapper:(id)arg1;
- (void)createPrefPanesForPlugInWrappers;
- (void)createPrefPaneForPlugInWrapper:(id)arg1;
- (void)copyIconImageNamed:(id)arg1 forPlugInWrapper:(id)arg2;
- (id)plugInWrapperWithIdentifier:(id)arg1;
- (void)plugInMenuItemAction:(id)arg1;
- (void)plugInAboutMenuItemAction:(id)arg1;
- (void)toggleVisibilityOfPlugInWrapper:(id)arg1;
- (void)hidePlugInWrapperInAllWindows:(id)arg1;
- (void)showPlugInWrapper:(id)arg1 inWindow:(id)arg2;
- (id)visiblePlugInWrappers;
- (void)hidePlugInWrapperWithViewPlacementMask:(int)arg1 inWindow:(id)arg2;
- (void)toggleVisibilityOfPlugInWrapper:(id)arg1 inWindow:(id)arg2;
- (struct _NSSize)drawerWillResizeContents:(id)arg1 toSize:(struct _NSSize)arg2;
- (void)toggleDrawerPlugInWrapper:(id)arg1 inWindow:(id)arg2;
- (void)toggleUtilityPanelPlugInWrapper:(id)arg1;
- (void)toggleFloatingUtilityPanelPlugInWrapper:(id)arg1;
- (void)toggleHUDPanelPlugInWrapper:(id)arg1;
- (void)toggleFloatingHUDPanelPlugInWrapper:(id)arg1;
- (void)togglePanelPluginWrapper:(id)arg1 isFloating:(BOOL)arg2 isHUD:(BOOL)arg3;
- (void)windowWillClose:(id)arg1;
- (id)createPanelWithContentView:(id)arg1 isHUD:(BOOL)arg2;
- (void)toggleSplitViewTopPlugInWrapper:(id)arg1 inWindow:(id)arg2;
- (void)toggleSplitViewBottomPlugInWrapper:(id)arg1 inWindow:(id)arg2;
- (void)toggleSplitViewLeftPlugInWrapper:(id)arg1 inWindow:(id)arg2;
- (void)toggleSplitViewRightPlugInWrapper:(id)arg1 inWindow:(id)arg2;
- (void)toggleSplitViewPluginWrapper:(id)arg1 isVertical:(BOOL)arg2 isFirst:(BOOL)arg3 inWindow:(id)arg4;
- (void)postNotificationName:(id)arg1 forPlugInWrapper:(id)arg2 viewController:(id)arg3;
- (void)postNotificationName:(id)arg1 forPlugInWrapper:(id)arg2 viewController:(id)arg3 userInfo:(id)arg4;
- (BOOL)isPanelMask:(int)arg1;
- (BOOL)isSplitViewMask:(int)arg1;
- (id)allPlugInIdentifiers;
- (void)setAllPlugInIdentifiers:(id)arg1;
- (id)plugInWrappers;
- (void)setPlugInWrappers:(id)arg1;
- (id)plugInController;
- (void)setPlugInController:(id)arg1;
- (id)windowsForPlugInIdentifier;
- (void)setWindowsForPlugInIdentifier:(id)arg1;

@end

@interface TODBrowserPlugInWrapper : NSObject
{
    id <TODBrowserPlugIn> plugIn;
    NSMutableDictionary *viewControllers;
    NSMutableSet *visibleWindowNumbers;
    NSString *currentViewPlacementMaskKey;
}

- (id)initWithPlugIn:(id)arg1;
- (void)dealloc;
- (BOOL)isVisibleInWindowNumber:(int)arg1;
- (void)setIsVisible:(BOOL)arg1 inWindowNumber:(int)arg2;
- (id)plugInViewControllerForWindowNumber:(int)arg1;
- (id)makeViewControllerForWindowNumber:(int)arg1;
- (void)windowWillClose:(id)arg1;
- (int)currentViewPlacementMask;
- (void)setCurrentViewPlacementMask:(int)arg1;
- (id)preferencesViewController;
- (id)identifier;
- (id)localizedTitle;
- (int)allowedViewPlacementMask;
- (int)preferredViewPlacementMask;
- (id)preferredMenuItemKeyEquivalent;
- (unsigned int)preferredMenuItemKeyEquivalentModifierMask;
- (id)toolbarIconImageName;
- (id)preferencesIconImageName;
- (id)defaultsDictionary;
- (id)aboutInfoDictionary;
- (float)preferredHorizontalSplitPosition;
- (float)preferredVerticalSplitPosition;
- (int)preferredToolbarButtonType;
- (id)visibleWindowNumbers;
- (void)setVisibleWindowNumbers:(id)arg1;
- (id)currentViewPlacementMaskKey;
- (void)setCurrentViewPlacementMaskKey:(id)arg1;
- (id)viewControllers;
- (void)setViewControllers:(id)arg1;
- (id)plugIn;
- (void)setPlugIn:(id)arg1;

@end

@interface TODAbstractBasePreferences : OAPreferenceClient
{
    BOOL defaultsHaveChanged;
}

- (void)restoreDefaults:(id)arg1;
- (void)restoreDefaultsNoPrompt;
- (BOOL)haveAnyDefaultsChanged;
- (BOOL)defaultsHaveChanged;
- (void)setDefaultsHaveChanged:(BOOL)arg1;

@end

@interface TODUserAgentWindowController : NSWindowController
{
    NSString *lastUAString;
}

+ (id)instance;
- (id)initWithWindowNibName:(id)arg1;
- (void)dealloc;
- (void)showWindow:(id)arg1;
- (void)cancel:(id)arg1;
- (void)ok:(id)arg1;
- (id)lastUAString;
- (void)setLastUAString:(id)arg1;

@end

@interface TODAdvancedPreferences : TODAbstractBasePreferences
{
}

- (id)URLPatterns;
- (void)setURLPatterns:(id)arg1;

@end

@interface TODBrowserPythonScriptingBridge : NSObject <TODBrowserScriptingBridge>
{
}

+ (id)instance;
- (id)init;
- (void)handleWebFrame:(id)arg1;

@end

@interface TODBrowserDocumentController : NSDocumentController
{
    BOOL justLaunched;
}

- (id)init;
- (id)newDocumentWithRequest:(id)arg1 makeKey:(BOOL)arg2;
- (id)documentWithFrameName:(id)arg1;
- (id)fileExtensionsFromType:(id)arg1;
- (id)defaultType;
- (id)documentForURL:(id)arg1;
- (BOOL)reopenDocumentForURL:(id)arg1 withContentsOfURL:(id)arg2 error:(id *)arg3;
- (id)openDocumentWithContentsOfURL:(id)arg1 display:(BOOL)arg2 error:(id *)arg3;
- (id)openUntitledDocumentAndDisplay:(BOOL)arg1 error:(id *)arg2;
- (id)makeUntitledDocumentOfType:(id)arg1 error:(id *)arg2;
- (id)makeDocumentForURL:(id)arg1 withContentsOfURL:(id)arg2 ofType:(id)arg3 error:(id *)arg4;
- (BOOL)justLaunched;
- (void)setJustLaunched:(BOOL)arg1;

@end

@interface TODBackForwardMenuButton : TODBrowserToolbarButton
{
    NSTimer *timer;
    BOOL didShowMenu;
}

- (void)dealloc;
- (void)mouseDown:(id)arg1;
- (void)mouseUp:(id)arg1;
- (void)menuDidEndTracking:(id)arg1;
- (void)showMenu:(id)arg1;
- (id)createMenu;
- (void)menuItemClick:(id)arg1;
- (BOOL)didShowMenu;
- (void)setDidShowMenu:(BOOL)arg1;
- (id)timer;
- (void)setTimer:(id)arg1;

@end

@interface TODComparisonValueTransformer : NSValueTransformer
{
    int number;
    int comparisonType;
}

+ (Class)transformedValueClass;
+ (BOOL)allowsReverseTransformation;
- (id)initWithNumber:(int)arg1 comparisonType:(int)arg2;
- (id)transformedValue:(id)arg1;

@end

@interface TODWebView : WebView
{
    BOOL isMainBrowserWebView;
}

- (BOOL)isMainBrowserWebView;
- (void)setIsMainBrowserWebView:(BOOL)arg1;

@end

@interface TODThemeFrame : NSThemeFrame
{
    float chromeOpacity;
}

- (id)initWithFrame:(struct _NSRect)arg1 styleMask:(unsigned int)arg2 owner:(id)arg3;
- (void)dealloc;
- (void)windowDidBecomeMain:(id)arg1;
- (void)windowDidResignMain:(id)arg1;
- (float)chromeOpacity;
- (void)setChromeOpacity:(float)arg1;
- (struct _NSSize)sizeOfTitlebarToolbarButton;
- (struct _NSPoint)_toolbarButtonOrigin;
- (id)newCloseButton;
- (id)newToolbarButton;
- (id)contentFill;
- (id)titlebarFill;
- (id)statusbarFill;
- (float)cornerRadius;
- (float)statusbarHeight;
- (float)bookmarkbarHeight;
- (float)toolbarHeight;
- (struct _NSPoint)_closeButtonOrigin;
- (struct _NSRect)_contentRectExcludingToolbar;
- (struct _NSRect)titlebarRect;
- (id)titleFont;
- (struct _NSRect)_titlebarTitleRect;
- (void)drawRect:(struct _NSRect)arg1;
- (void)_drawTitleBar:(struct _NSRect)arg1;
- (void)_drawStatusBar;
- (void)_drawResizeIndicators:(struct _NSRect)arg1;
- (void)_showToolbarWithAnimation:(BOOL)arg1;
- (void)_hideToolbarWithAnimation:(BOOL)arg1;
- (void)_drawTitleString;

@end

@interface TODBrowserToolbarButton : NSButton
{
}

+ (Class)cellClass;
- (BOOL)isOpaque;
- (BOOL)isTransparent;
- (unsigned int)imagePosition;
- (void)update;

@end

@interface TODBrowserStatusBarButton : TODBrowserToolbarButton
{
}

+ (Class)cellClass;
- (void)awakeFromNib;

@end

@interface TODBrowserToolbarButtonCell : NSButtonCell
{
    BOOL _tod_obscured;
}

- (BOOL)isObscured;
- (void)setObscured:(BOOL)arg1;
- (BOOL)isOpaque;
- (BOOL)isTransparent;
- (int)highlightsBy;
- (int)showsStateBy;
- (unsigned int)imagePosition;
- (id)backgroundColor;

@end

@interface TODBookmarkBarButtonCell : HMButtonCell
{
}

- (int)windowStyle;
- (id)foregroundColor;
- (id)highlightedForegroundColor;
- (id)shadowColor;
- (id)highlightedShadowColor;
- (id)highlightedBackgroundColor;
- (id)pressedBackgroundColor;
- (id)initTextCell:(id)arg1;
- (id)_textAttributes;
- (void)drawWithFrame:(struct _NSRect)arg1 inView:(id)arg2;

@end

@interface TODStatusItemThemeFrame : NSThemeFrame
{
}

+ (float)_titlebarHeight:(unsigned int)arg1;
+ (float)_resizeHeight:(unsigned int)arg1;
+ (BOOL)_resizeFromEdge;
- (float)statusbarHeight;
- (float)bookmarkbarHeight;
- (float)toolbarHeight;
- (float)cornerRadius;
- (struct _NSRect)contentRectForFrameRect:(struct _NSRect)arg1 styleMask:(unsigned int)arg2;
- (void)drawRect:(struct _NSRect)arg1;
- (struct _NSRect)titlebarRect;
- (void)_drawTitleBar:(struct _NSRect)arg1;
- (id)newCloseButton;
- (id)newMiniaturizeButton;
- (id)newZoomButton;
- (void)_drawResizeIndicators:(struct _NSRect)arg1;

@end

@interface TODStatusItemView : NSView
{
    NSImage *image;
    BOOL highlited;
}

- (id)initWithFrame:(struct _NSRect)arg1;
- (void)toggleMenu;
- (void)menuDidClose:(id)arg1;
- (void)rightMouseDown:(id)arg1;
- (void)mouseDown:(id)arg1;
- (void)mouseUp:(id)arg1;
- (void)dealloc;
- (void)drawRect:(struct _NSRect)arg1;
- (void)setImage:(id)arg1;
- (id)image;
- (BOOL)isHighlited;
- (void)setHighlited:(BOOL)arg1;

@end

@interface TODTinyURLResolver : NSObject
{
    id <TODTinyURLResolverDelegate> delegate;
    NSMutableDictionary *connections;
}

+ (id)tinyURLDomains;
- (id)init;
- (void)dealloc;
- (BOOL)canResolveURL:(id)arg1;
- (BOOL)canResolveURLString:(id)arg1;
- (BOOL)resolveTinyURLString:(id)arg1;
- (id)connection:(id)arg1 willSendRequest:(id)arg2 redirectResponse:(id)arg3;
- (void)connection:(id)arg1 didReceiveResponse:(id)arg2;
- (void)connection:(id)arg1 didReceiveData:(id)arg2;
- (void)connectionDidFinishLoading:(id)arg1;
- (void)connection:(id)arg1 didFailWithError:(id)arg2;
- (id)connection:(id)arg1 willCacheResponse:(id)arg2;
- (id)connections;
- (void)setConnections:(id)arg1;
- (id)delegate;
- (void)setDelegate:(id)arg1;

@end

@interface HMBlkBox : NSView
{
}

- (void)drawRect:(struct _NSRect)arg1;

@end

@interface HMBlkButton : NSButton
{
}

+ (Class)cellClass;
- (void)hmWindow:(id)arg1 mouseMoved:(id)arg2;

@end

@interface HMBlkButtonCell : NSButtonCell
{
}

- (void)drawInteriorWithFrame:(struct _NSRect)arg1 inView:(id)arg2;

@end

@interface HMBlkContentView : NSView
{
    BOOL _isResizing;
    BOOL _isDragging;
    struct _NSRect _startWindowFrame;
    struct _NSPoint _startLocation;
}

+ (void)load;
- (id)initWithFrame:(struct _NSRect)arg1;
- (void)mouseDown:(id)arg1;
- (void)mouseDragged:(id)arg1;
- (void)mouseUp:(id)arg1;
- (void)drawRect:(struct _NSRect)arg1;

@end

@interface HMBlkOutlineView : NSOutlineView
{
}

+ (void)load;
- (void)_init;
- (id)initWithFrame:(struct _NSRect)arg1;
- (id)initWithCoder:(id)arg1;
- (void)_sendDelegateWillDisplayCell:(id)arg1 forColumn:(id)arg2 row:(int)arg3;
- (void)_sendDelegateWillDisplayOutlineCell:(id)arg1 inOutlineTableColumnAtRow:(int)arg2;
- (id)_alternatingRowBackgroundColors;
- (id)_highlightColorForCell:(id)arg1;

@end

@interface HMBlkPanel : NSPanel
{
    HMBlkContentView *_blkContentView;
    HMBlkButton *_closeButton;
    NSMutableSet *_mouseMoveListeners;
    NSTimer *_fadeOutTimer;
}

+ (id)contentBackgroundImage;
+ (id)highlighedCellColor;
+ (id)alternatingRowBackgroundColors;
+ (id)majorGridColor;
- (id)initWithContentRect:(struct _NSRect)arg1 styleMask:(unsigned int)arg2 backing:(unsigned int)arg3 defer:(BOOL)arg4;
- (void)dealloc;
- (void)setContentView:(id)arg1;
- (BOOL)hasShadow;
- (BOOL)becomesKeyOnlyIfNeeded;
- (void)addMouseMoveListener:(id)arg1;
- (void)removeMouseMoveListener:(id)arg1;
- (BOOL)canBecomeMainWindow;
- (void)resetFadeOutTimer;
- (void)displayTimerExpired:(id)arg1;
- (void)fadeOutTimerExpired:(id)arg1;

@end

@interface HMBlkProgressIndicator : NSProgressIndicator
{
}

- (void)_drawThemeBackground;
- (void)_drawThemeProgressArea:(BOOL)arg1;

@end

@interface HMBlkSegmentedCell : NSSegmentedCell
{
}

+ (void)load;
- (void)drawWithFrame:(struct _NSRect)arg1 inView:(id)arg2;

@end

@interface HMBlkSegmentedControl : NSSegmentedControl
{
}

+ (void)initialize;
- (id)font;
- (id)attributedStringValue;

@end

@interface HMBlkTableHeaderCell : NSTableHeaderCell
{
}

- (id)textColor;
- (void)_drawThemeContents:(struct _NSRect)arg1 highlighted:(BOOL)arg2 inView:(id)arg3;

@end

@interface HMBlkTableView : NSTableView
{
}

- (void)_init;
- (id)initWithFrame:(struct _NSRect)arg1;
- (id)initWithCoder:(id)arg1;
- (void)_sendDelegateWillDisplayCell:(id)arg1 forColumn:(id)arg2 row:(int)arg3;
- (id)_alternatingRowBackgroundColors;
- (id)_highlightColorForCell:(id)arg1;

@end

@interface HMBlkScrollView : WebDynamicScrollBarsView
{
}

- (void)_init;
- (id)initWithFrame:(struct _NSRect)arg1;
- (id)initWithCoder:(id)arg1;
- (void)drawRect:(struct _NSRect)arg1;

@end

@interface HMBlkScroller : NSScroller
{
    BOOL vertical;
}

+ (void)initialize;
- (void)drawArrow:(unsigned int)arg1 highlightPart:(int)arg2;
- (void)drawKnob;
- (void)drawKnobSlotInRect:(struct _NSRect)arg1 highlight:(BOOL)arg2;
- (BOOL)isVertical;
- (void)setVertical:(BOOL)arg1;

@end

@interface SRValidator : NSObject
{
    id delegate;
}

- (id)initWithDelegate:(id)arg1;
- (void)dealloc;
- (BOOL)isKeyCode:(short)arg1 andFlagsTaken:(unsigned int)arg2 error:(id *)arg3;
- (BOOL)isKeyCode:(short)arg1 andFlags:(unsigned int)arg2 takenInMenu:(id)arg3 error:(id *)arg4;
- (id)delegate;
- (void)setDelegate:(id)arg1;

@end

@interface SRRecorderCell : NSActionCell <NSCoding>
{
    CTGradient *recordingGradient;
    NSString *autosaveName;
    BOOL isRecording;
    BOOL mouseInsideTrackingArea;
    BOOL mouseDown;
    int style;
    BOOL isAnimating;
    double transitionProgress;
    BOOL isAnimatingNow;
    BOOL isAnimatingTowardsRecording;
    BOOL comboJustChanged;
    int removeTrackingRectTag;
    int snapbackTrackingRectTag;
    struct _KeyCombo keyCombo;
    BOOL hasKeyChars;
    NSString *keyChars;
    NSString *keyCharsIgnoringModifiers;
    unsigned int allowedFlags;
    unsigned int requiredFlags;
    unsigned int recordingFlags;
    BOOL allowsKeyOnly;
    BOOL escapeKeysRecord;
    NSSet *cancelCharacterSet;
    SRValidator *validator;
    id delegate;
    BOOL globalHotKeys;
    void *hotKeyModeToken;
}

+ (BOOL)styleSupportsAnimation:(int)arg1;
- (id)init;
- (void)dealloc;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (BOOL)animates;
- (void)setAnimates:(BOOL)arg1;
- (int)style;
- (void)setStyle:(int)arg1;
- (void)drawWithFrame:(struct _NSRect)arg1 inView:(id)arg2;
- (void)resetTrackingRects;
- (void)mouseEntered:(id)arg1;
- (void)mouseExited:(id)arg1;
- (BOOL)trackMouse:(id)arg1 inRect:(struct _NSRect)arg2 ofView:(id)arg3 untilMouseUp:(BOOL)arg4;
- (id)delegate;
- (void)setDelegate:(id)arg1;
- (BOOL)becomeFirstResponder;
- (BOOL)resignFirstResponder;
- (BOOL)performKeyEquivalent:(id)arg1;
- (void)flagsChanged:(id)arg1;
- (unsigned int)allowedFlags;
- (void)setAllowedFlags:(unsigned int)arg1;
- (BOOL)allowsKeyOnly;
- (BOOL)escapeKeysRecord;
- (void)setAllowsKeyOnly:(BOOL)arg1 escapeKeysRecord:(BOOL)arg2;
- (unsigned int)requiredFlags;
- (void)setRequiredFlags:(unsigned int)arg1;
- (struct _KeyCombo)keyCombo;
- (void)setKeyCombo:(struct _KeyCombo)arg1;
- (BOOL)canCaptureGlobalHotKeys;
- (void)setCanCaptureGlobalHotKeys:(BOOL)arg1;
- (id)autosaveName;
- (void)setAutosaveName:(id)arg1;
- (id)keyComboString;
- (id)keyChars;
- (id)keyCharsIgnoringModifiers;

@end

@interface SRRecorderControl : NSControl
{
    id delegate;
}

+ (void)initialize;
+ (Class)cellClass;
- (id)initWithFrame:(struct _NSRect)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (void)dealloc;
- (BOOL)acceptsFirstResponder;
- (BOOL)acceptsFirstMouse:(id)arg1;
- (BOOL)becomeFirstResponder;
- (BOOL)resignFirstResponder;
- (BOOL)animates;
- (void)setAnimates:(BOOL)arg1;
- (int)style;
- (void)setStyle:(int)arg1;
- (void)viewDidMoveToWindow;
- (void)viewFrameDidChange:(id)arg1;
- (void)setFrameSize:(struct _NSSize)arg1;
- (void)setFrame:(struct _NSRect)arg1;
- (id)keyChars;
- (id)keyCharsIgnoringModifiers;
- (BOOL)performKeyEquivalent:(id)arg1;
- (void)flagsChanged:(id)arg1;
- (void)keyDown:(id)arg1;
- (unsigned int)allowedFlags;
- (void)setAllowedFlags:(unsigned int)arg1;
- (BOOL)allowsKeyOnly;
- (void)setAllowsKeyOnly:(BOOL)arg1 escapeKeysRecord:(BOOL)arg2;
- (BOOL)escapeKeysRecord;
- (BOOL)canCaptureGlobalHotKeys;
- (void)setCanCaptureGlobalHotKeys:(BOOL)arg1;
- (unsigned int)requiredFlags;
- (void)setRequiredFlags:(unsigned int)arg1;
- (struct _KeyCombo)keyCombo;
- (void)setKeyCombo:(struct _KeyCombo)arg1;
- (id)autosaveName;
- (void)setAutosaveName:(id)arg1;
- (id)keyComboString;
- (unsigned int)cocoaToCarbonFlags:(unsigned int)arg1;
- (unsigned int)carbonToCocoaFlags:(unsigned int)arg1;
- (id)delegate;
- (void)setDelegate:(id)arg1;
- (BOOL)shortcutRecorderCell:(id)arg1 isKeyCode:(short)arg2 andFlagsTaken:(unsigned int)arg3 reason:(id *)arg4;
- (void)shortcutRecorderCell:(id)arg1 keyComboDidChange:(struct _KeyCombo)arg2;

@end

@interface SRSharedImageProvider : NSObject
{
}

+ (id)supportingImageWithName:(id)arg1;

@end

@interface SRDummyClass : NSObject
{
}

@end

@interface SRKeyCodeTransformer : NSValueTransformer
{
}

+ (void)initialize;
+ (BOOL)allowsReverseTransformation;
+ (Class)transformedValueClass;
- (id)transformedValue:(id)arg1;
- (id)reverseTransformedValue:(id)arg1;

@end

@interface CTGradient : NSObject <NSCopying, NSCoding>
{
    struct _CTGradientElement *elementList;
    int blendingMode;
    struct CGFunction *gradientFunction;
}

+ (id)gradientWithBeginningColor:(id)arg1 endingColor:(id)arg2;
+ (id)aquaSelectedGradient;
+ (id)aquaNormalGradient;
+ (id)aquaPressedGradient;
+ (id)unifiedSelectedGradient;
+ (id)unifiedNormalGradient;
+ (id)unifiedPressedGradient;
+ (id)unifiedDarkGradient;
+ (id)sourceListSelectedGradient;
+ (id)sourceListUnselectedGradient;
+ (id)rainbowGradient;
+ (id)hydrogenSpectrumGradient;
- (id)init;
- (void)_commonInit;
- (void)dealloc;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)gradientWithAlphaComponent:(float)arg1;
- (id)gradientWithBlendingMode:(int)arg1;
- (id)addColorStop:(id)arg1 atPosition:(float)arg2;
- (id)removeColorStopAtPosition:(float)arg1;
- (id)removeColorStopAtIndex:(unsigned int)arg1;
- (int)blendingMode;
- (id)colorStopAtIndex:(unsigned int)arg1;
- (id)colorAtPosition:(float)arg1;
- (void)drawSwatchInRect:(struct _NSRect)arg1;
- (void)fillRect:(struct _NSRect)arg1 angle:(float)arg2;
- (void)radialFillRect:(struct _NSRect)arg1;
- (void)setBlendingMode:(int)arg1;
- (void)addElement:(struct _CTGradientElement *)arg1;
- (struct _CTGradientElement)removeElementAtIndex:(unsigned int)arg1;
- (struct _CTGradientElement)removeElementAtPosition:(float)arg1;
- (struct _CTGradientElement *)elementAtIndex:(unsigned int)arg1;

@end

@interface PTHotKey : NSObject
{
    NSString *mIdentifier;
    NSString *mName;
    PTKeyCombo *mKeyCombo;
    id mTarget;
    SEL mAction;
}

- (id)init;
- (id)initWithIdentifier:(id)arg1 keyCombo:(id)arg2;
- (void)dealloc;
- (id)description;
- (void)setIdentifier:(id)arg1;
- (id)identifier;
- (void)setKeyCombo:(id)arg1;
- (id)keyCombo;
- (void)setName:(id)arg1;
- (id)name;
- (void)setTarget:(id)arg1;
- (id)target;
- (void)setAction:(SEL)arg1;
- (SEL)action;
- (void)invoke;

@end

@interface PTHotKeyCenter : NSObject
{
    NSMutableDictionary *mHotKeys;
    BOOL mEventHandlerInstalled;
}

+ (id)sharedCenter;
- (id)init;
- (void)dealloc;
- (BOOL)registerHotKey:(id)arg1;
- (void)unregisterHotKey:(id)arg1;
- (id)allHotKeys;
- (id)hotKeyWithIdentifier:(id)arg1;
- (id)_hotKeyForCarbonHotKey:(struct OpaqueEventHotKeyRef *)arg1;
- (struct OpaqueEventHotKeyRef *)_carbonHotKeyForHotKey:(id)arg1;
- (void)_updateEventHandler;
- (void)_hotKeyDown:(id)arg1;
- (void)_hotKeyUp:(id)arg1;
- (void)sendEvent:(id)arg1;
- (long)sendCarbonEvent:(struct OpaqueEventRef *)arg1;

@end

@interface PTKeyCombo : NSObject <NSCopying>
{
    int mKeyCode;
    unsigned int mModifiers;
}

+ (id)clearKeyCombo;
+ (id)keyComboWithKeyCode:(int)arg1 modifiers:(unsigned int)arg2;
- (id)initWithKeyCode:(int)arg1 modifiers:(unsigned int)arg2;
- (id)initWithPlistRepresentation:(id)arg1;
- (id)plistRepresentation;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (BOOL)isEqual:(id)arg1;
- (int)keyCode;
- (unsigned int)modifiers;
- (BOOL)isValidHotKeyCombo;
- (BOOL)isClearCombo;

@end

@interface TODUberView : NSView
{
    NSSplitView *vSplitView;
    NSSplitView *hSplitView;
    NSView *leftSuperview;
    NSView *rightSuperview;
    NSView *bottomSuperview;
    NSView *midSuperview;
    NSView *topSuperview;
    NSView *leftView;
    NSView *rightView;
    NSView *bottomView;
    NSView *midView;
    NSView *topView;
    BOOL leftViewOpen;
    BOOL rightViewOpen;
    BOOL topViewOpen;
    BOOL bottomViewOpen;
    NSTimer *timer;
    int splitViewDividerStyle;
    float preferredLeftSplitWidth;
    float preferredRightSplitWidth;
    float preferredTopSplitHeight;
    float preferredBottomSplitHeight;
    BOOL snapsToPreferredSplitWidths;
    float snapTolerance;
    float dragStartMidWidth;
    float dragStartRightRatio;
    float dragStartLeftRatio;
    float dragStartMidHeight;
    float dragStartTopRatio;
    float dragStartBottomRatio;
}

- (id)initWithFrame:(struct _NSRect)arg1;
- (id)initWithFrame:(struct _NSRect)arg1 dividerStyle:(int)arg2;
- (void)dealloc;
- (BOOL)isFlipped;
- (void)resetToPreferredSplitPositions:(id)arg1;
- (void)toggleLeftView:(id)arg1;
- (void)openLeftView:(id)arg1;
- (void)closeLeftView:(id)arg1;
- (void)toggleRightView:(id)arg1;
- (void)openRightView:(id)arg1;
- (void)closeRightView:(id)arg1;
- (void)toggleTopView:(id)arg1;
- (void)openTopView:(id)arg1;
- (void)closeTopView:(id)arg1;
- (void)toggleBottomView:(id)arg1;
- (void)openBottomView:(id)arg1;
- (void)closeBottomView:(id)arg1;
- (float)splitView:(id)arg1 constrainMinCoordinate:(float)arg2 ofSubviewAt:(int)arg3;
- (float)splitView:(id)arg1 constrainMaxCoordinate:(float)arg2 ofSubviewAt:(int)arg3;
- (float)splitView:(id)arg1 constrainSplitPosition:(float)arg2 ofSubviewAt:(int)arg3;
- (float)vSplitView:(id)arg1 constrainSplitPosition:(float)arg2 ofSubviewAt:(int)arg3;
- (float)hSplitView:(id)arg1 constrainSplitPosition:(float)arg2 ofSubviewAt:(int)arg3;
- (void)splitView:(id)arg1 resizeSubviewsWithOldSize:(struct _NSSize)arg2;
- (void)vSplitView:(id)arg1 resizeSubviewsWithOldSize:(struct _NSSize)arg2;
- (void)hSplitView:(id)arg1 resizeSubviewsWithOldSize:(struct _NSSize)arg2;
- (void)splitViewDidResizeSubviews:(id)arg1;
- (void)timerFired:(id)arg1;
- (void)storeSplitPositions;
- (void)storeOpenStates;
- (void)storeLeftSplitPosition;
- (void)storeRightSplitPosition;
- (void)storeTopSplitPosition;
- (void)storeBottomSplitPosition;
- (void)restoreSplitPositions;
- (void)restoreOpenStates;
- (float)storedLeftSplitPosition;
- (void)restoreLeftSplitPosition;
- (float)storedRightSplitPosition;
- (void)restoreRightSplitPosition;
- (float)storedTopSplitPosition;
- (void)restoreTopSplitPosition;
- (float)storedBottomSplitPosition;
- (void)restoreBottomSplitPosition;
- (id)leftView;
- (void)setLeftView:(id)arg1;
- (id)rightView;
- (void)setRightView:(id)arg1;
- (id)topView;
- (void)setTopView:(id)arg1;
- (id)midView;
- (void)setMidView:(id)arg1;
- (id)bottomView;
- (void)setBottomView:(id)arg1;
- (int)splitViewDividerStyle;
- (void)setSplitViewDividerStyle:(int)arg1;
- (void)resetCapturing;
- (BOOL)isBottomViewOpen;
- (void)setBottomViewOpen:(BOOL)arg1;
- (BOOL)isTopViewOpen;
- (void)setTopViewOpen:(BOOL)arg1;
- (BOOL)isRightViewOpen;
- (void)setRightViewOpen:(BOOL)arg1;
- (BOOL)isLeftViewOpen;
- (void)setLeftViewOpen:(BOOL)arg1;
- (float)snapTolerance;
- (void)setSnapTolerance:(float)arg1;
- (BOOL)snapsToPreferredSplitWidths;
- (void)setSnapsToPreferredSplitWidths:(BOOL)arg1;
- (float)preferredBottomSplitHeight;
- (void)setPreferredBottomSplitHeight:(float)arg1;
- (float)preferredTopSplitHeight;
- (void)setPreferredTopSplitHeight:(float)arg1;
- (float)preferredRightSplitWidth;
- (void)setPreferredRightSplitWidth:(float)arg1;
- (float)preferredLeftSplitWidth;
- (void)setPreferredLeftSplitWidth:(float)arg1;
- (id)timer;
- (void)setTimer:(id)arg1;
- (id)midSuperview;
- (void)setMidSuperview:(id)arg1;
- (id)topSuperview;
- (void)setTopSuperview:(id)arg1;
- (id)bottomSuperview;
- (void)setBottomSuperview:(id)arg1;
- (id)rightSuperview;
- (void)setRightSuperview:(id)arg1;
- (id)leftSuperview;
- (void)setLeftSuperview:(id)arg1;
- (id)hSplitView;
- (void)setHSplitView:(id)arg1;
- (id)vSplitView;
- (void)setVSplitView:(id)arg1;

@end

@interface TODUberViewSplitView : NSSplitView
{
    NSGradient *gradient;
    NSColor *borderColor;
}

- (id)initWithFrame:(struct _NSRect)arg1;
- (void)dealloc;
- (void)drawDividerInRect:(struct _NSRect)arg1;
- (float)dividerThickness;
- (id)gradient;
- (void)setGradient:(id)arg1;
- (id)borderColor;
- (void)setBorderColor:(id)arg1;

@end

@interface TODAllPlugInPreferences : TODAbstractBasePreferences
{
}

@end

@interface TODShortcutPreferences : TODAbstractBasePreferences
{
    NSArrayController *arrayController;
    NSMutableArray *shortcuts;
}

- (void)dealloc;
- (void)insertObject:(id)arg1 inShortcutsAtIndex:(int)arg2;
- (void)removeObjectFromShortcutsAtIndex:(int)arg1;
- (void)storeShortcutsInUserDefaults;
- (void)startObservingRule:(id)arg1;
- (void)stopObservingRule:(id)arg1;
- (void)changeKeyPath:(id)arg1 ofObject:(id)arg2 toValue:(id)arg3;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)controlTextDidEndEditing:(id)arg1;
- (id)shortcuts;
- (void)setShortcuts:(id)arg1;

@end

@interface HMButton : NSButton
{
}

+ (Class)cellClass;
- (BOOL)isSeparator;
- (void)setSeparator:(BOOL)arg1;
- (BOOL)isSelected;
- (void)setSelected:(BOOL)arg1;
- (id)selectedImage;
- (void)setSelectedImage:(id)arg1;

@end

@interface HMButtonCell : NSButtonCell
{
    BOOL _isSeparator;
    BOOL _isSelected;
    NSImage *_selectedImage;
}

- (void)dealloc;
- (BOOL)isSeparator;
- (void)setSeparator:(BOOL)arg1;
- (BOOL)isSelected;
- (void)setSelected:(BOOL)arg1;
- (id)selectedImage;
- (void)setSelectedImage:(id)arg1;
- (void)_drawSeparatorWithFrame:(struct _NSRect)arg1 inView:(id)arg2;
- (void)_drawSelectedImageWithFrame:(struct _NSRect)arg1 inView:(id)arg2;
- (void)drawInteriorWithFrame:(struct _NSRect)arg1 inView:(id)arg2;

@end

@interface TODUserstylePreferences : TODAbstractBasePreferences
{
    NSArrayController *arrayController;
    NSTextView *textView;
    NSMutableArray *userstyles;
}

- (void)dealloc;
- (void)awakeFromNib;
- (void)insertObject:(id)arg1 inUserstylesAtIndex:(int)arg2;
- (void)removeObjectFromUserstylesAtIndex:(int)arg1;
- (void)storeUserstyles;
- (void)startObservingRule:(id)arg1;
- (void)stopObservingRule:(id)arg1;
- (void)changeKeyPath:(id)arg1 ofObject:(id)arg2 toValue:(id)arg3;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)controlTextDidEndEditing:(id)arg1;
- (id)userstyles;
- (void)setUserstyles:(id)arg1;

@end

@interface TODUserstyleController : NSObject
{
    NSURL *defaultCSSURL;
    NSURL *tempCSSURL;
    NSString *tempCSSPath;
    NSString *defaultCSSText;
}

+ (id)instance;
- (id)init;
- (void)dealloc;
- (void)webViewDidCommitLoadForMainFrame:(id)arg1;
- (id)uid;
- (void)setUserstyleToDefault:(id)arg1;
- (id)userstyleSourceForURLString:(id)arg1;
- (id)userstyles;
- (id)copyPreferences:(id)arg1;
- (id)defaultCSSText;
- (void)setDefaultCSSText:(id)arg1;
- (id)tempCSSPath;
- (void)setTempCSSPath:(id)arg1;
- (id)tempCSSURL;
- (void)setTempCSSURL:(id)arg1;
- (id)defaultCSSURL;
- (void)setDefaultCSSURL:(id)arg1;

@end

@interface TODShortcutController : NSObject
{
}

- (id)URLStringsForCommand:(id)arg1 isTabbed:(char *)arg2 isPiped:(char *)arg3;
- (id)URLStringWithFormat:(id)arg1 queryTokens:(id)arg2;
- (id)URLStringWithFormat:(id)arg1 query:(id)arg2;
- (id)replacementStringForshortcutKey:(id)arg1;
- (id)replacementFormatForshortcutKey:(id)arg1 isIndexed:(char *)arg2;
- (id)shortcuts;

@end

@interface TDHtmlSyntaxHighlighter : NSObject
{
    BOOL isDarkBG;
    BOOL inScript;
    TDTokenizer *tokenizer;
    NSMutableArray *stack;
    TDToken *ltToken;
    TDToken *gtToken;
    TDToken *startCommentToken;
    TDToken *endCommentToken;
    TDToken *startCDATAToken;
    TDToken *endCDATAToken;
    TDToken *startPIToken;
    TDToken *endPIToken;
    TDToken *startDoctypeToken;
    TDToken *fwdSlashToken;
    TDToken *eqToken;
    TDToken *scriptToken;
    TDToken *endScriptToken;
    NSMutableAttributedString *highlightedString;
    NSDictionary *tagAttributes;
    NSDictionary *textAttributes;
    NSDictionary *attrNameAttributes;
    NSDictionary *attrValueAttributes;
    NSDictionary *eqAttributes;
    NSDictionary *commentAttributes;
    NSDictionary *piAttributes;
}

- (id)init;
- (id)initWithAttributesForDarkBackground:(BOOL)arg1;
- (void)dealloc;
- (id)attributedStringForString:(id)arg1;
- (id)nextNonWhitespaceTokenFrom:(id)arg1;
- (void)consumeWhitespaceOnStack;
- (void)workOnComment;
- (void)workOnCDATA;
- (void)workOnPI;
- (void)workOnDoctype;
- (void)workOnScript;
- (void)workOnStartTag:(id)arg1;
- (void)workOnEndTag:(id)arg1;
- (void)workOnTag;
- (void)workOnText;
- (id)objectsAbove:(id)arg1;
- (id)peek;
- (id)pop;
- (id)piAttributes;
- (void)setPiAttributes:(id)arg1;
- (id)commentAttributes;
- (void)setCommentAttributes:(id)arg1;
- (id)eqAttributes;
- (void)setEqAttributes:(id)arg1;
- (id)attrValueAttributes;
- (void)setAttrValueAttributes:(id)arg1;
- (id)attrNameAttributes;
- (void)setAttrNameAttributes:(id)arg1;
- (id)textAttributes;
- (void)setTextAttributes:(id)arg1;
- (id)tagAttributes;
- (void)setTagAttributes:(id)arg1;
- (id)highlightedString;
- (void)setHighlightedString:(id)arg1;
- (id)endScriptToken;
- (void)setEndScriptToken:(id)arg1;
- (id)scriptToken;
- (void)setScriptToken:(id)arg1;
- (id)eqToken;
- (void)setEqToken:(id)arg1;
- (id)fwdSlashToken;
- (void)setFwdSlashToken:(id)arg1;
- (id)startDoctypeToken;
- (void)setStartDoctypeToken:(id)arg1;
- (id)endPIToken;
- (void)setEndPIToken:(id)arg1;
- (id)startPIToken;
- (void)setStartPIToken:(id)arg1;
- (id)endCDATAToken;
- (void)setEndCDATAToken:(id)arg1;
- (id)startCDATAToken;
- (void)setStartCDATAToken:(id)arg1;
- (id)endCommentToken;
- (void)setEndCommentToken:(id)arg1;
- (id)startCommentToken;
- (void)setStartCommentToken:(id)arg1;
- (id)gtToken;
- (void)setGtToken:(id)arg1;
- (id)ltToken;
- (void)setLtToken:(id)arg1;
- (id)tokenizer;
- (void)setTokenizer:(id)arg1;
- (id)stack;
- (void)setStack:(id)arg1;

@end

@interface TDSourceCodeTextView : NSTextView
{
    TDGutterView *gutterView;
    NSScrollView *scrollView;
    float sourceTextViewOffset;
}

- (void)dealloc;
- (void)awakeFromNib;
- (void)textDidChange:(id)arg1;
- (void)viewBoundsChanged:(id)arg1;
- (void)renderGutter;
- (void)registerForNotifications;
- (void)getRectsOfVisibleLines:(id *)arg1 startingLineNumber:(unsigned int *)arg2;
- (unsigned int)lineNumberForIndex:(unsigned int)arg1;
- (id)gutterView;
- (void)setGutterView:(id)arg1;

@end

@interface TDGutterView : NSView
{
    NSScrollView *sourceScrollView;
    NSTextView *sourceTextView;
    NSArray *lineNumberRects;
    unsigned int startLineNumber;
    NSDictionary *attrs;
}

- (void)awakeFromNib;
- (void)dealloc;
- (BOOL)isFlipped;
- (unsigned int)autoresizingMask;
- (void)drawRect:(struct _NSRect)arg1;
- (id)attrs;
- (void)setAttrs:(id)arg1;
- (unsigned int)startLineNumber;
- (void)setStartLineNumber:(unsigned int)arg1;
- (id)lineNumberRects;
- (void)setLineNumberRects:(id)arg1;
- (id)sourceTextView;
- (void)setSourceTextView:(id)arg1;
- (id)sourceScrollView;
- (void)setSourceScrollView:(id)arg1;

@end

@interface TODFindPanelView : NSView
{
    NSGradient *gradient;
    NSColor *borderColor;
}

- (id)initWithFrame:(struct _NSRect)arg1;
- (void)dealloc;
- (void)drawRect:(struct _NSRect)arg1;
- (id)gradient;
- (void)setGradient:(id)arg1;
- (id)borderColor;
- (void)setBorderColor:(id)arg1;

@end

@interface TODDownloadListButton : NSButton
{
}

+ (Class)cellClass;
- (void)dealloc;
- (void)awakeFromNib;

@end

@interface TODDownloadListButtonCell : NSButtonCell
{
}

- (void)awakeFromNib;

@end

@interface TODDownloadListBackgroundView : NSView
{
}

- (BOOL)isFlipped;
- (void)drawRect:(struct _NSRect)arg1;

@end

@interface TODWindowBackgroundView : NSView
{
}

- (void)drawRect:(struct _NSRect)arg1;

@end

@interface TODDefaultThemeFrame : NSThemeFrame
{
}

- (void)_drawResizeIndicators:(struct _NSRect)arg1;

@end

@interface TODTabViewItem : NSTabViewItem
{
}

@end

@interface TODSearchPreferences : TODAbstractBasePreferences
{
}

@end

@interface NSBezierPath (AMShading)
- (void)linearGradientFillWithStartColor:(id)arg1 endColor:(id)arg2;
- (void)bilinearGradientFillWithOuterColor:(id)arg1 innerColor:(id)arg2;
- (void)customHorizontalFillWithCallbacks:(struct CGFunctionCallbacks)arg1 firstColor:(id)arg2 secondColor:(id)arg3;
@end

@interface WebView (rss)
- (BOOL)hasRSSLink;
- (id)RSSLinks;
@end

@interface NSURL (FluidSupport)
- (BOOL)matchedInPatternsForKey:(id)arg1;
- (BOOL)isGoogleReaderURL;
- (BOOL)isGmailURL;
- (BOOL)isGoogleAppsURL;
- (BOOL)isYahooMailURL;
- (BOOL)isFacebookURL;
- (BOOL)isFlickrURL;
- (BOOL)isMobileMeURL;
- (BOOL)isUserscriptDotOrgURL;
- (BOOL)isMailToURL;
- (BOOL)isJavaScriptURL;
- (BOOL)isGoogleSearchURL;
- (BOOL)domainMatchesURL:(id)arg1;
- (BOOL)matchesURLPatterns:(id)arg1;
- (BOOL)isUserscriptURL;
@end

@interface TODAppDelegate (OpenContentsSupport)
- (void)handleInternetOpenContentsEvent:(id)arg1 replyEvent:(id)arg2;
- (void)handleOpenContentsAppleEventWithURL:(id)arg1;
- (void)handleMailToURL:(id)arg1;
- (void)handleFeedURL:(id)arg1;
- (void)googleReaderQuickAddFeedURL:(id)arg1;
- (void)gmailComposeMessageWithMailToURL:(id)arg1;
- (void)yahooMailComposeMessageWithMailToURL:(id)arg1;
- (void)getEmailAddr:(id *)arg1 args:(id *)arg2 fromMailToURL:(id)arg3;
- (void)clickElementInFrontWindowWithId:(id)arg1;
- (void)evaluateScriptInFrontWindow:(id)arg1;
@end

@interface TODAppDelegate (DockMenuSupport)
- (id)applicationDockMenu:(id)arg1;
- (void)getNewMail:(id)arg1;
- (void)doGetNewMail;
- (void)composeNewMessage:(id)arg1;
- (void)doComposeNewMessage;
- (void)gmailGetNewMail;
- (void)yahooMailGetNewMail;
@end

@interface TODAppDelegate (DockTileSupport)
- (void)setDockBadgeLabel:(id)arg1;
- (void)updateDockTileAtInterval;
- (void)updateDockTile;
- (id)labelForGoogleReaderDockTile;
- (id)labelForGmailDockTile;
- (id)labelForYahooMailDockTile;
- (id)labelForFacebookDockTile;
- (id)labelForFlickrDockTile;
- (id)substringFromString:(id)arg1 startDelimiter:(id)arg2 endDelimiter:(id)arg3;
@end

@interface TODBrowserWindowController (WebPolicyDelegate)
- (void)checkIfShouldCloseFrontWindow;
- (void)makeSystemOpenURL:(id)arg1;
- (void)webView:(id)arg1 decidePolicyForNewWindowAction:(id)arg2 request:(id)arg3 newFrameName:(id)arg4 decisionListener:(id)arg5;
- (void)webView:(id)arg1 decidePolicyForNavigationAction:(id)arg2 request:(id)arg3 frame:(id)arg4 decisionListener:(id)arg5;
- (void)webView:(id)arg1 decidePolicyForMIMEType:(id)arg2 request:(id)arg3 frame:(id)arg4 decisionListener:(id)arg5;
- (void)webView:(id)arg1 unableToImplementPolicyWithError:(id)arg2 frame:(id)arg3;
@end

@interface TODBrowserWindowController (WebUIDelegate)
- (void)webView:(id)arg1 setStatusText:(id)arg2;
- (void)webView:(id)arg1 mouseDidMoveOverElement:(id)arg2 modifierFlags:(unsigned int)arg3;
- (void)JSAlertSheetButtonClick:(id)arg1;
- (void)JSConfirmSheetButtonClick:(id)arg1;
- (void)alertSheetDidEnd:(id)arg1 returnCode:(int)arg2 contextInfo:(void *)arg3;
- (void)webView:(id)arg1 runJavaScriptAlertPanelWithMessage:(id)arg2;
- (BOOL)webView:(id)arg1 runJavaScriptConfirmPanelWithMessage:(id)arg2;
- (BOOL)webViewIsStatusBarVisible:(id)arg1;
- (id)webView:(id)arg1 createWebViewWithRequest:(id)arg2;
- (void)webViewShow:(id)arg1;
- (id)webView:(id)arg1 contextMenuItemsForElement:(id)arg2 defaultMenuItems:(id)arg3;
- (void)webView:(id)arg1 runOpenPanelForFileButtonWithResultListener:(id)arg2;
- (void)openPanelDidEnd:(id)arg1 returnCode:(int)arg2 contextInfo:(void *)arg3;
- (void)openLinkInNewTabFromMenu:(id)arg1;
- (void)openLinkInNewWindowFromMenu:(id)arg1;
- (void)openFrameInNewWindowFromMenu:(id)arg1;
- (void)openImageInNewWindowFromMenu:(id)arg1;
- (void)openInDefaultBrowserFromMenu:(id)arg1;
- (void)searchWebFromMenu:(id)arg1;
- (void)defineTermFromMenu:(id)arg1;
- (void)searchGoogleWithSelection:(id)arg1 isDefine:(BOOL)arg2;
- (void)resolveTinyURLFromMenu:(id)arg1;
- (void)makeTinyURLFromMenu:(id)arg1;
- (void)downForEveryoneOrJustMeFromMenu:(id)arg1;
- (id)currentSelectionFromWebView;
@end

@interface TODBrowserWindowController (WebFrameLoadDelegate)
- (void)webView:(id)arg1 didStartProvisionalLoadForFrame:(id)arg2;
- (void)webView:(id)arg1 didCommitLoadForFrame:(id)arg2;
- (void)webView:(id)arg1 didReceiveTitle:(id)arg2 forFrame:(id)arg3;
- (void)handleGoogleSERPInFrame:(id)arg1;
- (void)webView:(id)arg1 didFinishLoadForFrame:(id)arg2;
- (BOOL)willRetryWithTLDAdded:(id)arg1;
- (void)webView:(id)arg1 didFailProvisionalLoadWithError:(id)arg2 forFrame:(id)arg3;
- (void)webView:(id)arg1 didFailLoadWithError:(id)arg2 forFrame:(id)arg3;
- (void)webView:(id)arg1 didReceiveServerRedirectForProvisionalLoadForFrame:(id)arg2;
- (void)webView:(id)arg1 didClearWindowObject:(id)arg2 forFrame:(id)arg3;
- (void)webView:(id)arg1 didReceiveIcon:(id)arg2 forFrame:(id)arg3;
- (void)clearProgressInFuture;
- (void)clearProgress;
- (void)handleLoadError:(id)arg1;
@end

@interface TODBrowserWindowController (WebResourceLoadDelegate)
- (id)webView:(id)arg1 identifierForInitialRequest:(id)arg2 fromDataSource:(id)arg3;
- (void)webView:(id)arg1 resource:(id)arg2 didFailLoadingWithError:(id)arg3 fromDataSource:(id)arg4;
- (void)webView:(id)arg1 resource:(id)arg2 didReceiveResponse:(id)arg3 fromDataSource:(id)arg4;
@end

@interface TODBrowserWindowController (NSToolbarDelegate)
- (id)toolbarAllowedItemIdentifiers:(id)arg1;
- (id)toolbarDefaultItemIdentifiers:(id)arg1;
- (id)toolbar:(id)arg1 itemForItemIdentifier:(id)arg2 willBeInsertedIntoToolbar:(BOOL)arg3;
- (void)setupToolbar;
- (id)buttonToolbarItemWithIdentifier:(id)arg1 imageNamed:(id)arg2 label:(id)arg3 target:(id)arg4 action:(SEL)arg5 tag:(int)arg6;
- (id)viewToolbarItemWithIdentifier:(id)arg1 view:(id)arg2 label:(id)arg3 target:(id)arg4 action:(SEL)arg5;
- (id)toolbarItemWithIdentifier:(id)arg1 label:(id)arg2;
- (id)plugInToolbarItemWithPlugInWrapper:(id)arg1;
@end

@interface TODBrowserWindowController (WebScriptDebugDelegate)
- (void)webView:(id)arg1 didParseSource:(id)arg2 baseLineNumber:(unsigned int)arg3 fromURL:(id)arg4 sourceId:(int)arg5 forWebFrame:(id)arg6;
- (void)webView:(id)arg1 didEnterCallFrame:(id)arg2 sourceId:(int)arg3 line:(int)arg4 forWebFrame:(id)arg5;
- (void)webView:(id)arg1 willLeaveCallFrame:(id)arg2 sourceId:(int)arg3 line:(int)arg4 forWebFrame:(id)arg5;
@end

@interface NSBezierPath (RoundedRectangle)
+ (id)bezierPathWithRoundedRect:(struct _NSRect)arg1 cornerRadius:(float)arg2 inCorners:(int)arg3;
+ (id)bezierPathWithRoundedRect:(struct _NSRect)arg1 cornerRadius:(float)arg2;
@end

@interface DOMNode (FluidAdditions)
- (id)firstAncestorOrSelfByTagName:(id)arg1;
- (float)totalOffsetTop;
- (float)totalOffsetLeft;
@end

@interface NSToolbar (ToolbarItem)
- (id)toolbarItemWithIdentifier:(id)arg1;
@end

@interface NSOutlineView (ContextMenu)
- (id)menuForEvent:(id)arg1;
- (void)draggedImage:(id)arg1 endedAt:(struct _NSPoint)arg2 operation:(unsigned int)arg3;
@end

@interface NSOutlineView (ExpandingAndCollapsing)
- (void)expandAllItems;
- (void)collapseAllItems;
@end

@interface NSTableView (ContextMenu)
- (id)menuForEvent:(id)arg1;
@end

@interface NSNextStepFrame (appearance)
- (float)contentAlpha;
@end

@interface NSImage (Drawing)
- (void)drawInRect:(struct _NSRect)arg1 fromRect:(struct _NSRect)arg2 operation:(unsigned int)arg3 fraction:(float)arg4 contextRect:(struct _NSRect)arg5 isContextFlipped:(BOOL)arg6;
@end

@interface NSImage (Assemble)
+ (id)imageWithSize:(struct _NSSize)arg1 leftImage:(id)arg2 middleImage:(id)arg3 rightImage:(id)arg4 middleRect:(struct _NSRect *)arg5;
@end

@interface NSDocumentController (MIMEType)
- (id)typeFromMIMEType:(id)arg1;
@end

@interface NSBezierPath (ellipse)
+ (id)ellipseInRect:(struct _NSRect)arg1 withRadius:(float)arg2;
@end

@interface NSXMLNode (Extension)
- (id)singleNodeForXPath:(id)arg1;
- (id)stringValueForXPath:(id)arg1;
@end

@interface NSString (CharacterReference)
- (id)stringByReplacingCharacterReferences;
@end

@interface NSFileManager (UniqueFilePath)
- (id)makeUniqueFilePath:(id)arg1;
@end

@interface NSDate (DateFormat)
+ (void)load;
+ (id)dateFormats;
+ (void)addDateFromatsWithContentsOfFile:(id)arg1;
+ (void)addDateFormats:(id)arg1;
+ (void)removeDateFormats:(id)arg1;
+ (id)dateWithFormattedString:(id)arg1;
+ (id)formatForFormattedString:(id)arg1;
@end

@interface NSCharacterSet (NewLine)
+ (id)newLineCharacterSet;
@end

@interface NSAffineTransform (Extension)
+ (id)verticalFlipTransformForRect:(struct _NSRect)arg1;
- (struct _NSRect)transformRect:(struct _NSRect)arg1;
@end

@interface NSObject (SRValidation)
- (BOOL)shortcutValidator:(id)arg1 isKeyCode:(short)arg2 andFlagsTaken:(unsigned int)arg3 reason:(id *)arg4;
@end

@interface SRRecorderCell (Private)
- (void)_privateInit;
- (void)_createGradient;
- (void)_setJustChanged;
- (BOOL)_effectiveIsAnimating;
- (BOOL)_supportsAnimation;
- (void)_startRecordingTransition;
- (void)_endRecordingTransition;
- (void)_transitionTick;
- (void)_startRecording;
- (void)_endRecording;
- (id)_defaultsKeyForAutosaveName:(id)arg1;
- (void)_saveKeyCombo;
- (void)_loadKeyCombo;
- (struct _NSRect)_removeButtonRectForFrame:(struct _NSRect)arg1;
- (struct _NSRect)_snapbackRectForFrame:(struct _NSRect)arg1;
- (unsigned int)_filteredCocoaFlags:(unsigned int)arg1;
- (BOOL)_validModifierFlags:(unsigned int)arg1;
- (unsigned int)_filteredCocoaToCarbonFlags:(unsigned int)arg1;
- (BOOL)_isEmpty;
- (BOOL)shortcutValidator:(id)arg1 isKeyCode:(short)arg2 andFlagsTaken:(unsigned int)arg3 reason:(id *)arg4;
@end

@interface SRRecorderControl (Private)
- (void)resetTrackingRects;
@end

@interface SRSharedImageProvider (Private)
+ (id)_sizeSRSnapback;
+ (void)_drawSRSnapback:(id)arg1;
+ (id)_sizeSRRemoveShortcut;
+ (id)_sizeSRRemoveShortcutRollover;
+ (id)_sizeSRRemoveShortcutPressed;
+ (void)_drawARemoveShortcutBoxUsingRep:(id)arg1 opacity:(double)arg2;
+ (void)_drawSRRemoveShortcut:(id)arg1;
+ (void)_drawSRRemoveShortcutRollover:(id)arg1;
+ (void)_drawSRRemoveShortcutPressed:(id)arg1;
@end

@interface NSAlert (SRAdditions)
+ (id)alertWithNonRecoverableError:(id)arg1;
@end

@interface NSError (SRAdditions)
- (id)localizedDescription;
- (id)localizedFailureReason;
- (id)localizedRecoverySuggestion;
- (id)localizedRecoveryOptions;
@end

@interface NSBezierPath (SRAdditions)
+ (id)bezierPathWithSRCRoundRectInRect:(struct _NSRect)arg1 radius:(float)arg2;
@end

@interface SRKeyCodeTransformer (Private)
+ (void)regenerateStringToKeyCodeMapping;
@end

@interface TODAppDelegate (WebHistoryMenu)
- (void)setupHistory;
- (BOOL)isDateToday:(id)arg1;
- (int)numberOfItemsInHistoryMenu:(id)arg1;
- (BOOL)historyMenu:(id)arg1 updateItem:(id)arg2 atIndex:(int)arg3 shouldCancel:(BOOL)arg4;
@end

@interface NSArray (TDHtmlSyntaxHighlighterAdditions)
- (id)reversedMutableArray;
@end
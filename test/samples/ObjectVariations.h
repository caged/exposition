/**
 * Object With C structs
 */
@interface ITWebScroller : NSScroller
{
    struct UIScrollBar *mUIScrollBar;
    ITWebScroller *mPeer;
    struct ITScrollBar *mScrollBar;
}
- (id)initWithFrame:(struct _NSRect)arg1;
- (void)setPeer:(id)arg1;
- (void)setFrame:(struct _NSRect)arg1;
- (void)drawRect:(struct _NSRect)arg1;
- (void)syncScrollBar;
- (void)setNeedsDisplayInRect:(struct _NSRect)arg1;
- (void)dealloc;
@end



@interface ITNSMenuItemProxy : NSObject <NSValidatedUserInterfaceItem>
{
    int _tag;
    SEL _action;
}

- (id)initWithAction:(SEL)arg1;
- (SEL)action;
- (int)tag;

@end



#define SOmeEquation 12 * 34 + 86.0
#define SOmeFloat 23.0
#define SOmeInteger 123
#define SOmeType SOmeOtherType
#define WRITE_CHUNKSIZE    (1024 * 4)


#define PCRE_EXTRA_STUDY_DATA          0x0001
#define PCRE_EXTRA_MATCH_LIMIT         0x0002
#define PCRE_EXTRA_CALLOUT_DATA        0x0004

#define PCRE_DATE           21-May-2003
#define PCRE_ERROR_NOMATCH        (-1)
#define PCRE_DATA_SCOPE __declspec(dllexport)

#define ERR17 "unknown option bit(s) set"
#define ERR18 "missing ) after comment"
#define ERR19 "parentheses nested too deeply"

#define GTM_INLINE static __inline__ __attribute__((always_inline))
#define GTM_EXTERN extern "C"
#define GTM_EXPORT __attribute__((visibility("default")))
#define _GTMDevLog(...) NSLog(__VA_ARGS__)
#define NSIntegerMax    LONG_MAX

#define STATUS_MENU_ITEM_DEFAULT_PREFS  @"StatusMenuItemDefaultPrefs"
#define PREF_GROUP_STATUS_MENU_ITEM     @"Status Menu Item"
#define KEY_STATUS_MENU_ITEM_ENABLED    @"Status Menu Item Enabled"

#define NSCAssert1(condition, desc, arg1) NSCAssert((condition), (desc), (arg1))
#define NSCAssert(condition, desc, ...) \
    do {			\
	if (!(condition)) {	\
	    [[NSAssertionHandler currentHandler] handleFailureInFunction:[NSString stringWithUTF8String:__PRETTY_FUNCTION__] \
		file:[NSString stringWithUTF8String:__FILE__] \
	    	lineNumber:__LINE__ description:(desc), ##__VA_ARGS__]; \
	}			\
    } while(0)

NSString *const AsyncSocketException = @"AsyncSocketException";
NSString *const AsyncSocketErrorDomain = @"AsyncSocketErrorDomain";

static NSString *getaddrinfoLock = @"lock";

enum AsyncSocketFlags
{
	kEnablePreBuffering      = 1 << 0,  // If set, pre-buffering is enabled
	kDidPassConnectMethod    = 1 << 1,  // If set, disconnection results in delegate call
	kDidCallConnectDelegate  = 1 << 2,  // If set, connect delegate has been called
	kStartingTLS             = 1 << 3,  // If set, we're waiting for TLS negotiation to complete
	kForbidReadsWrites       = 1 << 4,  // If set, no new reads or writes are allowed
	kDisconnectAfterReads    = 1 << 5,  // If set, disconnect after no more reads are queued
	kDisconnectAfterWrites   = 1 << 6,  // If set, disconnect after no more writes are queued
	kClosingWithError        = 1 << 7,  // If set, the socket is being closed due to an error
};

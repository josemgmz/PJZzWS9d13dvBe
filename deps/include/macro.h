#if defined(CLANG_MVC)
#define DISABLE_WARNING_PUSH           __pragma(clang diagnostic push)
#define DISABLE_WARNING_POP            __pragma(clang diagnostic pop)
#define DISABLE_WARNING_RESERVED_ID    __pragma(clang diagnostic ignored "-Wreserved-id-macro")
#define DISABLE_WARNING_LANGUAGE_EXTENSION_TOKEN    __pragma(clang diagnostic ignored "-Wlanguage-extension-token")
#define DISABLE_WARNING_DOCUMENTATION    __pragma(clang diagnostic ignored "-Wdocumentation")
#define DISABLE_WARNING_CPP98_COMPAT_PENDATIC    __pragma(clang diagnostic ignored "-Wc++98-compat-pedantic")
#define DISABLE_WARNING_NO_PORTABLE_INCLUDE_PATH    __pragma(clang diagnostic ignored "-Wnonportable-system-include-path")
#define DISABLE_WARNING_DOCUMENTATION_UNKNOWN_COMMAND    __pragma(clang diagnostic ignored "-Wdocumentation-unknown-command")
#define DISABLE_WARNING_UNUSED_PARAMETER    __pragma(clang diagnostic ignored "-Wunused-parameter")
#define DISABLE_WARNING_MISSING_VARIABLE_DECLARATIONS __pragma(clang diagnostic ignored "-Wmissing-variable-declarations")
#define DISABLE_WARNING_MISSING_CASE_SWITCH __pragma(clang diagnostic ignored "-Wswitch")
#define DISABLE_WARNING_ZERO_AS_NULL_PTR __pragma(clang diagnostic ignored "-Wzero-as-null-pointer-constant")
#define DISABLE_WARNING_NOT_DEFINED __pragma(clang diagnostic ignored "-Wundef")
#define DISABLE_WARNING_IMPLICIT_CONVERSION_SIGNEDNESS __pragma(clang diagnostic ignored "-Wsign-conversion")
#define DISABLE_WARNING_IMPLICIT_OLD_STYLE_CAST __pragma(clang diagnostic ignored "-Wold-style-cast")
#define DISABLE_WARNING_REQUIRED_ALIGNMENT __pragma(clang diagnostic ignored "-Wcast-align")

#else
#define DISABLE_WARNING_PUSH
#define DISABLE_WARNING_POP
#define DISABLE_WARNING_RESERVED_ID    
#define DISABLE_WARNING_LANGUAGE_EXTENSION_TOKEN    
#define DISABLE_WARNING_DOCUMENTATION    
#define DISABLE_WARNING_CPP98_COMPAT_PENDATIC    
#define DISABLE_WARNING_NO_PORTABLE_INCLUDE_PATH  
#define DISABLE_WARNING_DOCUMENTATION_UNKNOWN_COMMAND 
#define DISABLE_WARNING_UNUSED_PARAMETER   
#define DISABLE_WARNING_MISSING_VARIABLE_DECLARATIONS
#define DISABLE_WARNING_MISSING_CASE_SWITCH
#define DISABLE_WARNING_ZERO_AS_NULL_PTR
#define DISABLE_WARNING_NOT_DEFINED
#define DISABLE_WARNING_IMPLICIT_CONVERSION_SIGNEDNESS
#define DISABLE_WARNING_IMPLICIT_OLD_STYLE_CAST
#define DISABLE_WARNING_REQUIRED_ALIGNMENT

#endif

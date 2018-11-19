#ifndef DC_BIND_CONFIG
#define DC_BIND_CONFIG 1

// Options.
#define	DC_BIND_OFFSET_DISABLE		NULL()	

// Default values.
#define DC_BIND_DEFAULT_INSTANCE	0
#define DC_BIND_DEFAULT_ENT			getlocalvar("self")
#define DC_BIND_DEFAULT_OFFSET_X	0
#define DC_BIND_DEFAULT_OFFSET_Y	0
#define DC_BIND_DEFAULT_OFFSET_Z	0
#define DC_BIND_DEFAULT_TARGET		NULL()

// Variable keys.
#define DC_BIND_VAR_KEY_INSTANCE	"dcbind_0"
#define DC_BIND_VAR_KEY_ENT			"dcbind_1"
#define DC_BIND_VAR_KEY_OFFSET_X	"dcbind_2"
#define DC_BIND_VAR_KEY_OFFSET_Y	"dcbind_3"
#define DC_BIND_VAR_KEY_OFFSET_Z	"dcbind_4"
#define DC_BIND_VAR_KEY_TARGET		"dcbind_5"

#endif // !DC_BIND_CONFIG
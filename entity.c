#include "data/scripts/dc_bind/config.h"

#import "data/scripts/dc_bind/instance.c"

// Base entity functions will act on.
// Get
void dc_bind_get_entity()
{
	int instance;
	void result;

	// Get instance.
	instance = dc_bind_get_instance();

	result = getlocalvar(instance + DC_BIND_VAR_KEY_ENT);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_BIND_DEFAULT_ENT;
	}

	return result;
}

// Set
void dc_bind_set_entity(void value)
{
	int instance;

	// Get instance.
	instance = dc_bind_get_instance();

	setlocalvar(instance + DC_BIND_VAR_KEY_ENT, value);
}

// Target entity (if any).
// Get
void dc_bind_get_target()
{
	int instance;
	void result;

	// Get instance.
	instance = dc_bind_get_instance();

	result = getlocalvar(instance + DC_BIND_VAR_KEY_TARGET);

	if (typeof(result) != openborconstant("VT_PTR"))
	{
		result = DC_BIND_DEFAULT_TARGET;
	}

	return result;
}

// Set
void dc_bind_set_target(void value)
{
	int instance;

	// Get instance.
	instance = dc_bind_get_instance();

	setlocalvar(instance + DC_BIND_VAR_KEY_TARGET, value);
}
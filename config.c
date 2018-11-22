#include "data/scripts/dc_bind/config.h"

// Which instance is in use?
int dc_bind_get_instance()
{
	void result = getlocalvar(DC_BIND_VAR_KEY_INSTANCE);

	if (!result)
	{
		result = DC_BIND_DEFAULT_INSTANCE;
	}

	return result;
}

void dc_bind_set_instance(int value)
{
	setlocalvar(DC_BIND_VAR_KEY_INSTANCE, value);
}

// Caskey, Damon V.
// 2018-11-22
//
// Clears the current instance, effectively resetting
// all values to their defaults.
void dc_bind_reset_instance()
{
	int instance;

	// Get instance.
	instance = dc_bind_get_instance();

	// Destroy all instance variables.
	dc_bind_free_instance();

	// If the instance ID isn't default, then restore 
	// it to memory. Either way we now have a clean
	// copy of the current instance.
	if (instance != DC_BIND_DEFAULT_INSTANCE)
	{
		dc_bind_set_instance(instance);
	}	
}

// Caskey, Damon V.
// 2018-11-22
//
// Destroy the current instance by deleting all
// library variables.
void dc_bind_free_instance()
{
	int instance;
	int i;
	char id;

	// Get instance.
	instance = dc_bind_get_instance();

	// Loop from 0 to end count of library variables.
	for (i = 0; i < DC_BIND_VAR_KEY_THE_END; i++)
	{
		// Concatenate the variable ID.
		id = instance + DC_BIND_VAR_KEY_BASE_ID + i;

		// Delete variable.
		setlocalvar(id, NULL());
	}
}

// Caskey, Damon V.
// 2018-11-22
//
// Send all library variables to log for debugging.
void dc_bind_dump_instance()
{
	int instance;
	int i;
	char id;

	// Get instance.
	instance = dc_bind_get_instance();

	// Log base name and instance.
	log("\n\n " + DC_BIND_VAR_KEY_BASE_ID + " dump:");
	log("\n\t " + "Instance: " + instance);

	// Loop from 0 to end count of instance variables.
	for (i = 0; i < DC_BIND_VAR_KEY_THE_END; i++)
	{
		// Concatenate the variable ID.
		id = instance + DC_BIND_VAR_KEY_BASE_ID + i;

		// Log ID.
		log("\n\t " + id + ": ");

		// Log value.
		log(getlocalvar(id));
	}

	// Log end point.
	log("\n End Dump.\n");
}

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

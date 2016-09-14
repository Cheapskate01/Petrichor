
#include "gdt.h"
#include "tty.h"

typedef void ( *constructor )();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors () {
	for ( constructor* i = &start_ctors; i != &end_ctors; i++ )
		(*i) ();
}

extern "C" void kerMain () {

	termInit ();

	/*write_string ("Hello World");*/

	GlobalDescriptorTable gdt;

	while ( 1 );
}
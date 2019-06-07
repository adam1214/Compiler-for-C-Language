#ifndef GLOBAL_H
#define GLOBAL_H

typedef enum { V_T, I_T, F_T, S_T, ID_T, B_T } Type;

typedef struct Value Value;
struct Value 
{
	Type type;
	union 
	{
		
		int i_val;
		float f_val;
		char* string; //for string constant

		struct //for ID
		{
            char *id_name;
            //Value *val_ptr;
		};
	};
};

#endif

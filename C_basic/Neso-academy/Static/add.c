//same as below, declear as global,
//available to this function and all other file in this project
//int count;
int var = 3;
//int static count = 0; //visible in this particular file only
//count not visible outside of this scope, this file only
//here global in this only
//advantage same as local to this particular func
/* Static var declared outside scope of any function will act like
global variable but only within the file it is declared*/
int increment()
{

    //static int count = var;
    //error static variable assign constant literal or value only
    int static count = 0; // local here,visible in this particular file and func
    count += 1;
    return count;
}

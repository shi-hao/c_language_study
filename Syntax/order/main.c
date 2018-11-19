//讨论一种计算次序的问题
#include<stdio.h>

static int global_var=5;

int mMul()
{
   return global_var*=2;
}

int mMinus()
{
   return global_var--;
}


int mPlus()
{
   return global_var++;
}


void main()
{
#if 1
  printf("mPlus + mMinus*mMul=%d\n",mPlus() + mMinus()*mMul());
  global_var = 5;
  printf("mPlus + (mMinus*mMul)=%d\n",mPlus() + (mMinus()*mMul()));
#endif
#if 0
  global_var = 5;
  printf("(global_var-=1) * (global_var*=2)=%d\n", (global_var-=1) * (global_var*=2));
  printf("(global_var-=1) * (global_var*=2)=%d\n", (global_var-=1) * (global_var*=2));
  //printf("global_var + (global_var--) * (global_var*=2)=%d\n", global_var+(global_var--) * (global_var*=2));
  printf("global_var=%d\n",global_var);
#endif
#if 0
  global_var = 5;
  printf("global_var*=2=%d\n",global_var*=2);
  global_var = 5;
  printf("global_var=global_var*2=%d\n",global_var=global_var*2);
#endif
}



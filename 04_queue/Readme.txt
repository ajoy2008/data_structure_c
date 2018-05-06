--------------------------------------------------------------------------------
Q: How to use the queue driver and queue application ??
A:
   Step1 :
   To create queue library "libqueue.a" inside driver/lib folder,
   Run the following commands :
   cd driver
   make clean
   make

   Step2 :
   After building the library, Enter into the application folder.
   Now choose the specific application you want and enter into the respective
   directory. Select the Flag (For example __ARR_QUEUE_S32__ or
   __LIST_QUEUE_S32__) in Makefile for the kind of implementation you want
   from driver layer.

   After above steps run the following command to build the application :
   make clean; make

   The above command will create ./bin/*.exe folder.
   Now run the application : ./bin/your_program.exe
--------------------------------------------------------------------------------
Q: What is the speciality of queue driver design ??
A: Queue driver design uses the same underlying concepts as Stack driver design.
   Before you proceed, Please read the stack driver design concepts first..
   Now, Lets move...So, here you will learn how best we can organize our driver
   code logically in multiple folder. See the speciality in driver Makefile....
   I hope you will love it....

[ NOTE: In your real project you may want to organize your source code logically
  in multiple folder. You can use/refer/modify this driver Makefile according to
  your needs.....
  .....Lets learn Queue now.....
]
--------------------------------------------------------------------------------

Q: How to use the stack driver and stack application ??
Ans:
    Step1 :
    To create stack library libstack.a inside driver/lib folder, Run the following commands :
    cd driver
    make clean
    make

    Step2 :
    Once after building the library, Enter into the application folder.
    Now choose the specific application you want and enter into the respective directory.
    run the following command to build the application :
    make clean; make

    The above command will create ./bin/*.exe folder.
    Now run the application : ./bin/your_program.exe


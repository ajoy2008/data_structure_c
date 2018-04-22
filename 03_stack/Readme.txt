--------------------------------------------------------------------------------
Q: How to use the stack driver and stack application ??
Ans:
    Step1 :
    To create stack library libstack.a inside driver/lib folder,
    Run the following commands :
    cd driver
    make clean
    make

    Step2 :
    After building the library, Enter into the application folder.
    Now choose the specific application you want and
    enter into the respective directory.
    Select the Flag (For example __ARR_STK_S32__ or __LIST_STK_S32__) in Makefile
    for the kind of implementation you want from driver layer.

    After above steps run the following command to build the application :
    make clean; make

    The above command will create ./bin/*.exe folder.
    Now run the application : ./bin/your_program.exe
--------------------------------------------------------------------------------
Q: What is the speciality of stack driver design ??
   If you notice, at the bottom (driver) layer I have implemented basic stack
   operations (Like PUSH, POP, TOP etc..) using array based approach and also
   using linked list based approach.
   But an abstraction layer is implemented (stack.h), so that user application
   need not to worry about wheather its a array based or linked list based stack.
   The user application is completely independant of array or
   linked list based implementation. The only thing user has to choose what kind
   of approach they want from bottom layer, by selecting a Makefile flag in the
   application.

   This kind of design having an advantage that any change happening in driver
   layer, application need not to worry about those changes.
   Application will still be same.

[ NOTE : This kind of design can be adopted in a situation where let say,
  You are working in common product for multiple customer.
  Let say customer A uses TI controller at its bottom layer,
  Customer B uses ARM controller at its bottom layer,
  Customet C uses Atmel controller at its bottom layer.
  But all customer uses a common application functionality.

  Such kind of situation you no need to build 3 drivers and 3 application for
  3 customers. Instead You can design your controller specfic functionality
  and abstract them to a common functionality (for example, spi_read(), spi_write(),
  i2c_read(), i2c_write() etc) and then build a single application
  using this common functionality for all the customers.

  While packaging the product only thing you have to do is to select the right
  controller for the right customer in your application.

  ...Thats all.....Hope this will give you some source of thinking...
  ...And eventually you will come up with some better design idea...
  ...Share with me once you found a new design idea...
]

--------------------------------------------------------------------------------

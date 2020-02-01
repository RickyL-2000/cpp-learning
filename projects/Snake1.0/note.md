# 开发心得、问题与解决方法

## 20/2/1   11:30

先只画出了Board，snake什么的都先不画，看看编译是否通过。

结果编译不通过，一顿操作后发现原因如下：

1. 在一个Snake中引用了Food，但是Snake的声明（定义）写在Food前面，导致找不到Food的declaration。  解决办法：在Snake之前声明class Food;
2. enum的类型和int原来是不一样的...导致定义与声明类型不符

原来X是横轴...Y是纵轴...
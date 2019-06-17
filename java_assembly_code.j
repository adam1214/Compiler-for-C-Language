.class public compiler_hw3
.super java/lang/Object
.method public static sqrt(I)I
.limit stack 50
.limit locals 50
	iload 0
	i2f
	iload 0
	i2f
	fmul
	f2i
	ireturn
.end method
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 5.000000
	f2i
	istore 0
	iload 0
	invokestatic compiler_hw3/sqrt(I)I
	i2f
	fstore 1
	fload 1
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	return
.end method

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

int init_hello(void)
{
	printk(KERN_ALERT "Hello Raspberry Jusu world\n");
	return 0;
}

void exit_hello(void){
	printk(KERN_ALERT "Good Raspberry junsu world\n");
}

module_init(init_hello);
module_exit(exit_hello);

MODULE_LICENSE("GPL");

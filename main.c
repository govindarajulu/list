#include <linux/module.h>
#include <linux/kernel.h>

static __init int modinit(void)
{
	printk(KERN_INFO"Hello World!\n");
	return 0;
}
static __exit void modexit(void)
{
	printk(KERN_INFO"bye cruel world\n");
}
module_init(modinit);
module_exit(modexit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("govind");

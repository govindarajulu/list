#include <linux/module.h>
#include <linux/kernel.h>
struct mylist{
	int data;
	struct list_head list;
};
struct list_head mylist;
static __init int modinit(void)
{
	struct mylist a, b, c, d, e;

	INIT_LIST_HEAD(&mylist);

	a.data = 1;
	INIT_LIST_HEAD(&a.list);

        b.data = 2;
        INIT_LIST_HEAD(&b.list);

	c.data = 3;
        INIT_LIST_HEAD(&b.list);

	d.data = 4;
        INIT_LIST_HEAD(&d.list);

	e.data = 5;
        INIT_LIST_HEAD(&e.list);

	list_add(&a.list, &mylist);
	list_add(&b.list, &mylist);
	list_add(&c.list, &mylist);
	list_add(&d.list, &mylist);

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

#include <linux/module.h>
#include <linux/kernel.h>
struct mylist{
	int data;
	struct list_head list;
};
struct list_head mylist;

void print_list(struct list_head *listhead)
{
	struct mylist *mylist = NULL;
	printk(KERN_INFO"--------------printing-list--------------\n");
	list_for_each_entry(mylist, listhead, list) {
		printk(KERN_INFO"%d\n", mylist->data);
	}
	printk(KERN_INFO"-----------------------------------------\n");
}
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

	print_list(&mylist);

	list_add(&a.list, &mylist);
	print_list(&mylist);
	list_add(&b.list, &mylist);
	print_list(&mylist);
	list_add(&c.list, &mylist);
	print_list(&mylist);
	list_add(&d.list, &mylist);
	print_list(&mylist);
	list_add(&e.list, &mylist);
	print_list(&mylist);

	list_del(&a.list);
	print_list(&mylist);
        list_del(&b.list);
        print_list(&mylist);
        list_del(&c.list);
        print_list(&mylist);
        list_del(&d.list);
        print_list(&mylist);
        list_del(&e.list);
	print_list(&mylist);

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

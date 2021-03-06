#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("Dual BSD/GPL");

/*
 * print the module information
 */
static void print_module(void)
{
    struct module *mod;

    printk(KERN_ALERT "this module: %p==%p\n", &__this_module, THIS_MODULE);
    printk(KERN_ALERT "module state: %d\n", THIS_MODULE->state);
    printk(KERN_ALERT "module name: %s\n", THIS_MODULE->name);

    list_for_each_entry(mod, *(&THIS_MODULE->list.prev), list);
    printk(KERN_ALERT "module name: %s\n", mod->name);
    printk(KERN_ALERT "module state: %d\n", THIS_MODULE->state);
}


static void print_vmarea()
{
    printf("---------------------\n");
    printf("TASK_SIZE = %p\n", TASK_SIZE);
    printf("---------------------\n");
    printf("STACK_TOP = %p\n", STACK_TOP);
    //printf("MMAP_BASE = %p\n", TASK_UNMAPPED_SIZE);
}


static int hello_init(void)
{
    print_module( );

    printk(KERN_ALERT "run in cpu %d\n", get_cpu());

    //printk(KERN_ALERT "PAGE_OFFSET : 0x%lx, TASK_SIZE : 0x%lx", PAGE_OFFSET, TASK_SIZE);
    printk(KERN_ALERT "PAGE_OFFSET : 0x%lx\n", PAGE_OFFSET);

    print_vmarea( );

    return 0;
}



static void hello_exit(void)
{
}


module_init(hello_init);
module_exit(hello_exit);

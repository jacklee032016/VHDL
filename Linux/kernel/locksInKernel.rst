
Locks in Kernel
########################################
01.20, 2019

Lock Usages
==================
1. Lock in user context
--------------------------
locking
+++++++++++++
* ``mutex_lock_interruptible()``: mutex can be interrupted by signal
* ``mutex_lock()``:

unlock
+++++++++++++
* ``mutex_unlock()``:

2. Lock between SoftIRQ/Tasklet/Timer and user context
--------------------------------------------------------
Problems:
+++++++++++++++
#. User context can be interrupted by softIRQ;
#. SoftIRQ can be entered by another CPU;
Resolution
++++++++++++++
* spin_lock_bh(): disables softirqs on that CPU, then grabs the lock;
* spin_unlock_bh():
* User context and SoftIRQ both call these functions to enter critical zone;

3. Lock between tasklets/timers
---------------------------------
* Tasklet/timer can only runs on one cpu even in SMP processor;
* Both tasklets/timers use spin_lock() and spin_unlock();

4. Lock between SoftIRQs
----------------------------
* Between diffrent SoftIRQs;
* Lock within same SoftIRQ: same SoftIRQ can runs in different CPUs at the same time;
* Using spin_lock() and spin_unlock();

5. Between ISR and SoftIRQ/Tasklet
-------------------------------------
Problems:
+++++++++++++++++++
#. SoftIRQ can be interrupted by ISR;
#. Critical zone in ISR( or SoftIRQ) can be entered in another CPU;
Resolution
+++++++++++++++++++
* spin_lock_irq(): disable interrupts on that cpu, then grab the lock;
* spin_unlock_irq():
* spin_lock_irqsave(): saves whether interrupts were on or off in a flags word, which is passed to spin_unlock_irqrestore(). 
* Option-1: 
   * SoftIRQ/Tasklet call spin_lock_irq(); 
   * ISR call spin_lock();
* Option-2:
   * SoftIRQ/Tasklet and ISR all call spin_lock_irq_save();   
2 Types of Locks
==================
No matter how many CPUs the processor has, these 2 types of locks are not recursive:

Only can be locked one time, eg. run in one CPU only;

spin_lock_t
----------------
spin: busy to wait, can't be re-scheduled;
Support only when CONFIG_SMP or CONFIG_PROEMPT is enabled

mutex
----------------
process/thread can be put into wait queue;

#. semaphore:
#. mutex:
#. rw_lock_t: optimized for one writer, multiple readers;



Executable context in kernel
===============================

#. ISR: multiple IRQs from same hardware can be served by multiple CPUs simutaneously;
#. SoftIrq: Same softIRQ can run multiple instances in multiple CPUs by ISR simultaneously;
#. tasklet: only running in one CPU, eg. only one instance can be running in OS
#. timer: one kind of tasklet(not softIRQ);
#. process/thread:

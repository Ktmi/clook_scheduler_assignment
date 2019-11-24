# Plan

Initial plan:
 - Modify ```elevator_add_req_fn``` to implement C-Look
   - ```elevator_add_req_fn``` is mapped to ```clook_add_req```
   - The list ```clook_add_req``` is inserting is sorted
   - Requests next to one another *should* be merged automatically
   - Insert before the first request in the list that ends on
     a later sector.

# Implementation
This project was based on linux kernel v4.20 from
Linus Torvalds repository.

The original source code was copied from NOOP, then had the character
sequence noop replaced with clook. ```clook_add_req``` was modified
to sort incoming requests.
```clook_add_req``` and ```clook_dispatch``` were modified to
print to the kernel the requests being queued or dispatched.


# Results
The kernel was able to be compiled, and the module added through insmod.
There was some difficulty due to the drive being attached through a
virtual scsi interface, which would default to multiqueuing, which
clook is not. This was overcome by applying the ```scsi_mod.use_blk_mq=0```
kernel flag.

The results where interesting. Requests where being added to the queue in
sequential order of there sector, making it very difficult to tell if the algorithm
was actually sorting the incoming requests. The only real reassurance
of it doing so is that the order of the dispatched requests is in order.

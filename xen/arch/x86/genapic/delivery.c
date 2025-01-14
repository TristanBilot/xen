#include <xen/irq.h>
#include <xen/sched.h>
#include <asm/current.h>
#include <asm/smp.h>
#include <asm/hardirq.h>
#include <mach_apic.h>

/*
 * LOGICAL FLAT DELIVERY MODE (multicast via bitmask to <= 8 logical APIC IDs).
 */

void init_apic_ldr_flat(void)
{
	unsigned long val;

	apic_write(APIC_DFR, APIC_DFR_FLAT);
	val = apic_read(APIC_LDR) & ~APIC_LDR_MASK;
	val |= SET_xAPIC_LOGICAL_ID(1UL << smp_processor_id());
	apic_write(APIC_LDR, val);
}

const cpumask_t *vector_allocation_cpumask_flat(int cpu)
{
	return &cpu_online_map;
} 

unsigned int cpu_mask_to_apicid_flat(const cpumask_t *cpumask)
{
	return cpumask_bits(cpumask)[0]&0xFF;
}

/*
 * PHYSICAL DELIVERY MODE (unicast to physical APIC IDs).
 */

void init_apic_ldr_phys(void)
{
	/* We only deliver in phys mode - no setup needed. */
}

const cpumask_t *vector_allocation_cpumask_phys(int cpu)
{
	return cpumask_of(cpu);
}

unsigned int cpu_mask_to_apicid_phys(const cpumask_t *cpumask)
{
	/* As we are using single CPU as destination, pick only one CPU here */
	return cpu_physical_id(cpumask_any(cpumask));
}

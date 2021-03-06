/*
 * FIFO-based event channel ABI.
 *
 * Copyright (C) 2013 Citrix Systems R&D Ltd.
 *
 * This source code is licensed under the GNU General Public License,
 * Version 2 or later.  See the file COPYING for more details.
 */
#ifndef __XEN_EVENT_FIFO_H__
#define __XEN_EVENT_FIFO_H__

int evtchn_fifo_init_control(struct evtchn_init_control *init_control);
int evtchn_fifo_expand_array(const struct evtchn_expand_array *expand_array);
void evtchn_fifo_destroy(struct domain *domain);

#endif /* __XEN_EVENT_FIFO_H__ */

/*
 * Local variables:
 * mode: C
 * c-file-style: "BSD"
 * c-basic-offset: 4
 * tab-width: 4
 * indent-tabs-mode: nil
 * End:
 */

select count(*) as clientes
from
	CUSTOMER,
	ORDERS,
	LINEITEM
where
	c_custkey = o_custkey
	and l_orderkey = o_orderkey
    and o_comment not like "%special request%";
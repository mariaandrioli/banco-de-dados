select n_name,
    sum(l_quantity) as encomendas
from
	CUSTOMER,
	ORDERS,
	LINEITEM,
	NATION
where
	c_custkey = o_custkey
	and l_orderkey = o_orderkey
	and c_nationkey = n_nationkey
group by
	n_name
order by
    encomendas desc
limit 10;
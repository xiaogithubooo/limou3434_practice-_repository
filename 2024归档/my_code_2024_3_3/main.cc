class ReadView
{
private:
    trx_id_t m_low_limit_id; //高水位（没写错），大于等于这个 ID 的事务均不可见
    trx_id_t m_up_limit_id; //低水位（没写错），小于等于这个 ID 的事务均可见
    
    trx_id_t m_creator_trx_id; //创建该 Read View 对象的事务 ID
    
    ids_t m_ids; //创建视图时的其他一起活跃事务的 ID 列表
    up_limit_id; //记录 m_ids 列表中事务 ID 最小的 ID（没有写错）
    low_limit_id; //Read View 生成时刻系统尚未分配的下一个事务 ID，就是目前已出现事务 ID 的最大值 +1（没有写错）

    trx_id_t m_low_limit_no; //配合 purge 值，了解一下就行，我们不关心
    bool m_closed; //标记视图是否被关闭，也不太关心
};
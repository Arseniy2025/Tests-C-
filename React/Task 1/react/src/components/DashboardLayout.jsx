function DashboardLayout({ children }) {
    return (
    <div style={{ display: 'flex', minHeight: '100vh' }}>
        <aside style={{ width: '220px', background: '#f0f0f0', padding: '20px' }}>
        <ul>
            <li>Профиль</li>
            <li>Настройки</li>
            <li>Статистика</li>
        </ul>
        </aside>

        <section style={{ flex: 1, padding: '20px' }}>
        {children}
        </section>
    </div>
    );
}

export default DashboardLayout;
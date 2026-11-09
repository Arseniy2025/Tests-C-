function PageLayout({ children }) {
    return (
    <div className="page-layout">
        <header className="main-header">
        <nav>Главная | О нас | Контакты</nav>
        </header>

        <main className="content-area">
        {children}
        </main>

        <footer className="main-footer">
        <p>Приложение</p>
        </footer>
    </div>
    );
}

export default PageLayout;
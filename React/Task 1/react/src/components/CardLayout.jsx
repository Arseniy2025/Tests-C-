function CardLayout({ children }) {
    return (
    <div style={{
        border: '1px solid #ddd',
        borderRadius: '8px',
        padding: '16px',
        boxShadow: '0 2px 4px rgba(0,0,0,0.1)',
        margin: '10px 0'
    }}>
        {children}
    </div>
    );
}

export default CardLayout;
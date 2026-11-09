import PageLayout from './components/PageLayout';
import DashboardLayout from './components/DashboardLayout';
import CardLayout from './components/CardLayout';

function App() {
  return (
    <PageLayout>
      <DashboardLayout>
        <CardLayout>
          <h3>Первая карточка</h3>
          <p>Контент...</p>
        </CardLayout>
        <CardLayout>
          <h3>Вторая карточка</h3>
          <p>Контент...</p>
        </CardLayout>
      </DashboardLayout>
    </PageLayout>
  );
}

export default App;
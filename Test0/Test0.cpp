#include "CppUnitTest.h"
#include "../Decision0/Furniture.h"
#include "../Decision0/Chair.h"
#include "../Decision0/Table.h"
#include "../Decision0/Cabinet.h"
#include "../Decision0/Order.h"
#include "../Decision0/CustomOrder.h"
#include "../Decision0/FurnitureStore.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FurnitureTests
{
    TEST_CLASS(FurnitureTest)
    {
    public:
        TEST_METHOD(BasicCreation)
        {
            // Создаем дату производства
            std::tm productionDate = {};
            productionDate.tm_year = 124; // 2024
            productionDate.tm_mon = 0;    // январь
            productionDate.tm_mday = 15;

            // Создаем базовую мебель
            Furniture furniture("Basic Furniture", "Мебель", 10000.0, 5, productionDate);

            Assert::AreEqual(std::string("Basic Furniture"), furniture.getName());
            Assert::AreEqual(10000.0, furniture.getPrice());
            Assert::AreEqual(5, furniture.getQuantity());
            Assert::AreEqual(std::string("Мебель"), furniture.getType());
        }

        TEST_METHOD(SellFurniture)
        {
            std::tm productionDate = {};
            productionDate.tm_year = 124;
            productionDate.tm_mon = 0;
            productionDate.tm_mday = 15;

            Furniture furniture("Test Furniture", "Мебель", 5000.0, 3, productionDate);

            // Продаем один товар
            bool sold = furniture.sell();
            Assert::IsTrue(sold);
            Assert::AreEqual(2, furniture.getQuantity());

            // Пытаемся продать больше, чем есть
            furniture.sell();
            furniture.sell();
            sold = furniture.sell(); // Должно быть 0
            Assert::IsFalse(sold);
        }

        TEST_METHOD(AddToStock)
        {
            std::tm productionDate = {};
            productionDate.tm_year = 124;
            productionDate.tm_mon = 0;
            productionDate.tm_mday = 15;

            Furniture furniture("Test Furniture", "Мебель", 5000.0, 3, productionDate);

            furniture.addToStock(5);
            Assert::AreEqual(8, furniture.getQuantity());
        }

        TEST_METHOD(SetPriceAndQuantity)
        {
            std::tm productionDate = {};
            productionDate.tm_year = 124;
            productionDate.tm_mon = 0;
            productionDate.tm_mday = 15;

            Furniture furniture("Test Furniture", "Мебель", 5000.0, 3, productionDate);

            furniture.setPrice(6000.0);
            furniture.setQuantity(10);

            Assert::AreEqual(6000.0, furniture.getPrice());
            Assert::AreEqual(10, furniture.getQuantity());
        }
    };

    TEST_CLASS(ChairTest)
    {
    public:
        TEST_METHOD(ChairCreation)
        {
            std::tm productionDate = {};
            productionDate.tm_year = 124;
            productionDate.tm_mon = 0;
            productionDate.tm_mday = 15;

            Chair chair("Office Chair", 15000.0, 8, productionDate, true, "Leather");

            Assert::AreEqual(std::string("Office Chair"), chair.getName());
            Assert::AreEqual(15000.0, chair.getPrice());
            Assert::AreEqual(8, chair.getQuantity());
            Assert::IsTrue(chair.getHasBackrest());
            Assert::AreEqual(std::string("Leather"), chair.getUpholstery());
            Assert::AreEqual(std::string("Стул"), chair.getType());
        }

        TEST_METHOD(ChairInfo)
        {
            std::tm productionDate = {};
            productionDate.tm_year = 124;
            productionDate.tm_mon = 0;
            productionDate.tm_mday = 15;

            Chair chair("Office Chair", 15000.0, 8, productionDate, true, "Leather");
            std::string info = chair.getInfo();

            // Проверяем что информация содержит основные данные
            Assert::IsTrue(info.find("Office Chair") != std::string::npos);
            Assert::IsTrue(info.find("15000") != std::string::npos);
            Assert::IsTrue(info.find("Спинка: есть") != std::string::npos);
            Assert::IsTrue(info.find("Leather") != std::string::npos);
        }
    };

    TEST_CLASS(TableTest)
    {
    public:
        TEST_METHOD(TableCreation)
        {
            std::tm productionDate = {};
            productionDate.tm_year = 124;
            productionDate.tm_mon = 0;
            productionDate.tm_mday = 15;

            Table table("Dining Table", 30000.0, 4, productionDate, 1.8, 0.9, "Rectangle");

            Assert::AreEqual(std::string("Dining Table"), table.getName());
            Assert::AreEqual(30000.0, table.getPrice());
            Assert::AreEqual(4, table.getQuantity());
            Assert::AreEqual(1.8, table.getLength());
            Assert::AreEqual(0.9, table.getWidth());
            Assert::AreEqual(std::string("Rectangle"), table.getShape());
            Assert::AreEqual(std::string("Стол"), table.getType());
        }

        TEST_METHOD(TableInfo)
        {
            std::tm productionDate = {};
            productionDate.tm_year = 124;
            productionDate.tm_mon = 0;
            productionDate.tm_mday = 15;

            Table table("Dining Table", 30000.0, 4, productionDate, 1.8, 0.9, "Rectangle");
            std::string info = table.getInfo();

            Assert::IsTrue(info.find("Dining Table") != std::string::npos);
            Assert::IsTrue(info.find("30000") != std::string::npos);
            Assert::IsTrue(info.find("1.8x0.9") != std::string::npos);
            Assert::IsTrue(info.find("Rectangle") != std::string::npos);
        }
    };

    TEST_CLASS(CabinetTest)
    {
    public:
        TEST_METHOD(CabinetCreation)
        {
            std::tm productionDate = {};
            productionDate.tm_year = 124;
            productionDate.tm_mon = 0;
            productionDate.tm_mday = 15;

            Cabinet cabinet("Bookshelf", 25000.0, 6, productionDate, 5, "Oak");

            Assert::AreEqual(std::string("Bookshelf"), cabinet.getName());
            Assert::AreEqual(25000.0, cabinet.getPrice());
            Assert::AreEqual(6, cabinet.getQuantity());
            Assert::AreEqual(5, cabinet.getShelvesCount());
            Assert::AreEqual(std::string("Oak"), cabinet.getMaterial());
            Assert::AreEqual(std::string("Шкаф"), cabinet.getType());
        }

        TEST_METHOD(CabinetInfo)
        {
            std::tm productionDate = {};
            productionDate.tm_year = 124;
            productionDate.tm_mon = 0;
            productionDate.tm_mday = 15;

            Cabinet cabinet("Bookshelf", 25000.0, 6, productionDate, 5, "Oak");
            std::string info = cabinet.getInfo();

            Assert::IsTrue(info.find("Bookshelf") != std::string::npos);
            Assert::IsTrue(info.find("25000") != std::string::npos);
            Assert::IsTrue(info.find("Полок: 5") != std::string::npos);
            Assert::IsTrue(info.find("Oak") != std::string::npos);
        }
    };

    TEST_CLASS(OrderTest)
    {
    public:
        TEST_METHOD(OrderCreation)
        {
            std::tm orderDate = {};
            orderDate.tm_year = 124;
            orderDate.tm_mon = 0;
            orderDate.tm_mday = 20;

            Order order(1, orderDate, "John Doe");

            Assert::AreEqual(1, order.getOrderId());
            Assert::AreEqual(std::string("John Doe"), order.getCustomerName());
            Assert::AreEqual(0.0, order.getTotalPrice());
            Assert::IsTrue(order.getItems().empty());
        }

        TEST_METHOD(AddItemsToOrder)
        {
            std::tm orderDate = {};
            orderDate.tm_year = 124;
            orderDate.tm_mon = 0;
            orderDate.tm_mday = 20;

            std::tm productionDate = {};
            productionDate.tm_year = 124;
            productionDate.tm_mon = 0;
            productionDate.tm_mday = 15;

            Order order(1, orderDate, "John Doe");

            auto chair = std::make_shared<Chair>("Office Chair", 15000.0, 5, productionDate, true, "Leather");
            auto table = std::make_shared<Table>("Coffee Table", 20000.0, 3, productionDate, 1.0, 0.5, "Oval");

            order.addItem(chair);
            order.addItem(table);

            Assert::AreEqual(2, (int)order.getItems().size());
            Assert::AreEqual(35000.0, order.getTotalPrice());
        }

        TEST_METHOD(OrderInfo)
        {
            std::tm orderDate = {};
            orderDate.tm_year = 124;
            orderDate.tm_mon = 0;
            orderDate.tm_mday = 20;

            Order order(1, orderDate, "John Doe");

            std::tm productionDate = {};
            productionDate.tm_year = 124;
            productionDate.tm_mon = 0;
            productionDate.tm_mday = 15;

            auto chair = std::make_shared<Chair>("Office Chair", 15000.0, 5, productionDate, true, "Leather");
            order.addItem(chair);

            std::string info = order.getInfo();
            Assert::IsTrue(info.find("Заказ #1") != std::string::npos);
            Assert::IsTrue(info.find("John Doe") != std::string::npos);
            Assert::IsTrue(info.find("15000") != std::string::npos);
        }
    };

    TEST_CLASS(CustomOrderTest)
    {
    public:
        TEST_METHOD(CustomOrderCreation)
        {
            std::tm orderDate = {};
            orderDate.tm_year = 124;
            orderDate.tm_mon = 0;
            orderDate.tm_mday = 25;

            CustomOrder customOrder(2, orderDate, "Jane Smith", 20.0, "Black matte finish");

            Assert::AreEqual(2, customOrder.getOrderId());
            Assert::AreEqual(std::string("Jane Smith"), customOrder.getCustomerName());
            Assert::AreEqual(20.0, customOrder.getMarkupPercentage());
            Assert::AreEqual(std::string("Black matte finish"), customOrder.getSpecialRequirements());
        }

        TEST_METHOD(ApplyMarkup)
        {
            std::tm orderDate = {};
            orderDate.tm_year = 124;
            orderDate.tm_mon = 0;
            orderDate.tm_mday = 25;

            CustomOrder customOrder(2, orderDate, "Jane Smith", 20.0, "Special finish");

            // Проверяем применение наценки
            double basePrice = 10000.0;
            double markedUpPrice = customOrder.applyMarkup(basePrice);
            Assert::AreEqual(12000.0, markedUpPrice);
        }

        TEST_METHOD(CustomOrderWithItems)
        {
            std::tm orderDate = {};
            orderDate.tm_year = 124;
            orderDate.tm_mon = 0;
            orderDate.tm_mday = 25;

            std::tm productionDate = {};
            productionDate.tm_year = 124;
            productionDate.tm_mon = 0;
            productionDate.tm_mday = 15;

            CustomOrder customOrder(2, orderDate, "Jane Smith", 20.0, "Special requirements");

            auto table = std::make_shared<Table>("Custom Table", 20000.0, 2, productionDate, 2.0, 1.0, "Custom");
            customOrder.addItem(table);

            // Цена должна быть с наценкой 20%
            Assert::AreEqual(24000.0, customOrder.getTotalPrice());
        }

        TEST_METHOD(CustomOrderInfo)
        {
            std::tm orderDate = {};
            orderDate.tm_year = 124;
            orderDate.tm_mon = 0;
            orderDate.tm_mday = 25;

            CustomOrder customOrder(2, orderDate, "Jane Smith", 20.0, "Special requirements");

            std::string info = customOrder.getInfo();
            Assert::IsTrue(info.find("ИНДИВИДУАЛЬНЫЙ ЗАКАЗ") != std::string::npos);
            Assert::IsTrue(info.find("Jane Smith") != std::string::npos);
            Assert::IsTrue(info.find("20%") != std::string::npos);
            Assert::IsTrue(info.find("Special requirements") != std::string::npos);
        }
    };

    TEST_CLASS(FurnitureStoreTest)
    {
    public:
        TEST_METHOD(StoreCreation)
        {
            FurnitureStore store;

            // Проверяем что магазин создан
            auto assortment = store.showAssortment();
            Assert::IsTrue(assortment.empty());
        }

        TEST_METHOD(AddFurnitureToStore)
        {
            FurnitureStore store;

            std::tm productionDate = {};
            productionDate.tm_year = 124;
            productionDate.tm_mon = 0;
            productionDate.tm_mday = 15;

            auto chair = std::make_shared<Chair>("Test Chair", 10000.0, 10, productionDate, true, "Fabric");
            store.addFurniture(chair);

            auto assortment = store.showAssortment();
            Assert::AreEqual(1, (int)assortment.size());
            Assert::AreEqual(std::string("Test Chair"), assortment[0]->getName());
        }

        TEST_METHOD(FindFurnitureByName)
        {
            FurnitureStore store;

            std::tm productionDate = {};
            productionDate.tm_year = 124;
            productionDate.tm_mon = 0;
            productionDate.tm_mday = 15;

            auto chair = std::make_shared<Chair>("Test Chair", 10000.0, 10, productionDate, true, "Fabric");
            store.addFurniture(chair);

            auto found = store.findFurnitureByName("Test Chair");
            Assert::IsNotNull(found.get());
            Assert::AreEqual(std::string("Test Chair"), found->getName());

            auto notFound = store.findFurnitureByName("Non-existent");
            Assert::IsNull(notFound.get());
        }

        TEST_METHOD(CreateAndAddOrder)
        {
            FurnitureStore store;

            std::tm productionDate = {};
            productionDate.tm_year = 124;
            productionDate.tm_mon = 0;
            productionDate.tm_mday = 15;

            auto chair = std::make_shared<Chair>("Test Chair", 10000.0, 10, productionDate, true, "Fabric");
            store.addFurniture(chair);

            auto order = store.createOrder("Test Customer");
            order->addItem(chair);
            store.addOrder(order);

            auto allOrders = store.getAllOrders();
            Assert::AreEqual(1, (int)allOrders.size());
        }

        TEST_METHOD(CalculateCustomOrderPrice)
        {
            FurnitureStore store;

            double basePrice = 10000.0;
            double markup = 20.0;
            double expectedPrice = 12000.0;

            double calculatedPrice = store.calculateCustomOrderPrice(basePrice, markup);
            Assert::AreEqual(expectedPrice, calculatedPrice);
        }

        TEST_METHOD(CreateCustomOrder)
        {
            FurnitureStore store;

            auto customOrder = store.createCustomOrder("Test Customer", 15.0, "Special finish");
            Assert::IsNotNull(customOrder.get());
            Assert::AreEqual(std::string("Test Customer"), customOrder->getCustomerName());
            Assert::AreEqual(15.0, customOrder->getMarkupPercentage());
            Assert::AreEqual(std::string("Special finish"), customOrder->getSpecialRequirements());
        }

        TEST_METHOD(GetSoldFurnitureCount)
        {
            FurnitureStore store;

            std::tm productionDate = {};
            productionDate.tm_year = 124;
            productionDate.tm_mon = 0;
            productionDate.tm_mday = 15;

            auto chair = std::make_shared<Chair>("Test Chair", 10000.0, 10, productionDate, true, "Fabric");
            store.addFurniture(chair);

            // Создаем заказ
            auto order = store.createOrder("Customer 1");
            order->addItem(chair);
            order->addItem(chair); // 2 стула в заказе
            store.addOrder(order);

            // Создаем диапазон дат
            std::tm startDate = {};
            startDate.tm_year = 124;
            startDate.tm_mon = 0;
            startDate.tm_mday = 1;

            std::tm endDate = {};
            endDate.tm_year = 124;
            endDate.tm_mon = 11;
            endDate.tm_mday = 31;

            int soldCount = store.getSoldFurnitureCount("Test Chair", startDate, endDate);
            Assert::AreEqual(2, soldCount);
        }

        TEST_METHOD(GetOrdersInPeriod)
        {
            FurnitureStore store;

            // Создаем несколько заказов
            auto order1 = store.createOrder("Customer 1");
            auto order2 = store.createOrder("Customer 2");
            store.addOrder(order1);
            store.addOrder(order2);

            // Создаем диапазон дат
            std::tm startDate = {};
            startDate.tm_year = 124;
            startDate.tm_mon = 0;
            startDate.tm_mday = 1;

            std::tm endDate = {};
            endDate.tm_year = 124;
            endDate.tm_mon = 11;
            endDate.tm_mday = 31;

            auto ordersInPeriod = store.getOrdersInPeriod(startDate, endDate);
            Assert::AreEqual(2, (int)ordersInPeriod.size());
        }

        TEST_METHOD(StoreStatistics)
        {
            FurnitureStore store;

            std::tm productionDate = {};
            productionDate.tm_year = 124;
            productionDate.tm_mon = 0;
            productionDate.tm_mday = 15;

            // Добавляем разную мебель
            auto chair = std::make_shared<Chair>("Test Chair", 10000.0, 5, productionDate, true, "Fabric");
            auto table = std::make_shared<Table>("Test Table", 20000.0, 3, productionDate, 1.5, 0.8, "Rectangle");
            auto cabinet = std::make_shared<Cabinet>("Test Cabinet", 30000.0, 2, productionDate, 4, "Oak");

            store.addFurniture(chair);
            store.addFurniture(table);
            store.addFurniture(cabinet);

            // Добавляем заказ
            auto order = store.createOrder("Test Customer");
            order->addItem(chair);
            store.addOrder(order);

            std::string stats = store.getStatistics();

            // Проверяем что статистика содержит ожидаемую информацию
            Assert::IsTrue(stats.find("Ассортимент: 3") != std::string::npos);
            Assert::IsTrue(stats.find("Заказов всего: 1") != std::string::npos);
        }
    };
}
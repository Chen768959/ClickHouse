#include <DataTypes/DataTypeString.h>
#include <DataTypes/DataTypesNumber.h>
#include <Databases/DatabaseFactory.h>
#include <Storages/System/StorageSystemDatabaseEngines.h>

namespace DB
{

NamesAndTypesList StorageSystemDatabaseEngines::getNamesAndTypes()
{
    return {
        {"name", std::make_shared<DataTypeString>()},
    };
}

void StorageSystemDatabaseEngines::fillData(MutableColumns & res_columns, ContextPtr, const SelectQueryInfo &) const
{
    for (const auto & [engine, _] : DatabaseFactory::instance().getDatabaseEngines())
    {
        int i = 0;
        res_columns[i++]->insert(engine);
    }
}

}

//
// Created by sphdx on 6/23/25.
//

#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <string>
#include "../model/PersonName.h"
#include "../include/model/HashTableKey.h"

namespace repo {
    using ToKey = model::HashTableKey(*)(const model::PersonName &, const model::Date &);
}

#endif //REPOSITORY_H

//
// Created by sphdx on 7/7/25.
//

#ifndef STUDENTUISTATE_H
#define STUDENTUISTATE_H
#include "model/Student.h"
#include <string>

namespace app::ui::state {
    struct StudentState {
        static constexpr size_t kNameBuf = 128;
        static constexpr size_t kClassBuf = 16;
        static constexpr size_t kDateBuf = 32;
        static constexpr size_t kPageSize = 20;
        static constexpr size_t kPathBuf = 256;

        // поп-апы
        bool open_add{};
        bool open_del{};
        bool open_search{};

        // ошибки
        bool add_err{};
        bool del_err{};
        bool search_err{};
        bool save_err{};

        std::string err_details;

        bool open_dialog{};

        // поиск
        bool search_active{};
        model::HashTableKey search_key;
        Vector<model::Student> cached;
        bool cached_found{};
        size_t step_counter;

        // ввод
        char name[kNameBuf] = "";
        char class_name[kClassBuf] = "";
        char birth_date[kDateBuf] = "";
        char path[kPathBuf] = "";

        // пагинация
        size_t current_page{};
    };
}
#endif //STUDENTUISTATE_H
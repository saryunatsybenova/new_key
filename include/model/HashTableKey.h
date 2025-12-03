#ifndef HASHTABLEKEY_H
#define HASHTABLEKEY_H

#include "PersonName.h"
#include "Date.h"

namespace model {
    class HashTableKey {
        PersonName name_;
        Date birth_date_;

    public:
        HashTableKey(PersonName name, Date birth_date);
        HashTableKey(const HashTableKey& other);
        HashTableKey();

        [[nodiscard]] std::string to_string() const;

        [[nodiscard]] model::PersonName get_name() const;
        [[nodiscard]] Date get_birth_date() const;

        friend std::ostream& operator<<(std::ostream& os, const HashTableKey& hashtablekey);

        bool operator<(const HashTableKey& other) const;
        bool operator>(const HashTableKey& other) const;
        bool operator==(const HashTableKey& other) const;
    };

    inline std::ostream& operator<<(std::ostream& os, const HashTableKey& hashtablekey) {
        return os << hashtablekey.to_string();
    }

    inline std::string HashTableKey::to_string() const {
        return name_.to_string() + '\t' + birth_date_.to_string();
    }

    inline model::PersonName HashTableKey::get_name() const {
        return name_;
    }

    inline Date HashTableKey::get_birth_date() const {
        return birth_date_;
    }

    inline HashTableKey::HashTableKey(model::PersonName name, Date birth_date) :
        name_(std::move(name)),
        birth_date_(birth_date) {
        if (!birth_date)
            throw std::invalid_argument("Дата рождения не указана");
    }

    inline HashTableKey::HashTableKey(const HashTableKey& other) = default;

    inline HashTableKey::HashTableKey() = default;

    inline bool HashTableKey::operator<(const HashTableKey& other) const {
        if (name_ != other.name_) return name_ < other.name_;
        return birth_date_ < other.birth_date_;
    }

    inline bool HashTableKey::operator>(const HashTableKey& other) const {
        return other < *this;
    }

    inline bool HashTableKey::operator==(const HashTableKey& other) const {
        return name_ == other.name_ && birth_date_ == other.birth_date_;
    }
}

#endif //HASHTABLEKEY_H

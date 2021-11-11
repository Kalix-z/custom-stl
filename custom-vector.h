#pragma once
#include <iostream>
#include <stdint.h>

namespace kstd {

    template <typename type> class vector {
    private:
        type* m_array;
        size_t m_maxSize;
        size_t m_curSize;
    public:
        vector() {
            m_maxSize = 5;
            m_curSize = 0;
            m_array = (type*) malloc(m_maxSize * sizeof(type));
            if (m_array == nullptr) {
                std::cout << "memory error\n";
                return;
            }
        }

        void push_back(type val) {   
            if (m_curSize == m_maxSize) {
                m_maxSize *= 2;
                /* copying the old values to the new array */
                type* tempArray = (type*)malloc(m_maxSize * sizeof(type));
                if (tempArray == nullptr) {
                    std::cout << "memory error\n";
                    return;
                }
                memcpy(tempArray, m_array, m_curSize * sizeof(type));
                free(m_array);
                m_array = (type*)tempArray;
            }
            memcpy(&m_array[m_curSize], &val, sizeof(val));
            m_curSize++;
        }

        type& operator[] (size_t index) {
            return m_array[index];
        }

        size_t size() const {
            return m_curSize;
        }

        type front() const {
            return m_array[0];
        }

        type back() const {
            return m_array[m_curSize-1];
        }

        ~vector() {
            free( m_array);
        }
    };

}

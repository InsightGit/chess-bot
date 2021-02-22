//
// Created by bobby on 16/02/2021.
//

#ifndef CHESS_BOT_VECTOR_2_HPP
#define CHESS_BOT_VECTOR_2_HPP

#include <cstdint>

namespace chess {
    class Vector2 {
    public:
        Vector2(int x, int y) {
            // if we want to save some memory at the expense of code simplicity, define this preprocessor definition
            #ifndef _DISABLE_XY
                m_x = x;
                m_y = y;
            #endif

            m_composite = m_x + (m_y * 8);
        }

        Vector2() : Vector2(0, 0) {}

        #ifndef _DISABLE_XY
            uint8_t get_x() const {
                return m_x;
            }

            uint8_t get_y() const {
                return m_y;
            }
        #endif

        uint8_t get_composite() const {
            return m_composite;
        }

        bool operator==(const Vector2 &other) const {
            return m_composite == other.m_composite;
        }
    private:
        uint8_t m_composite;

        #ifndef _DISABLE_XY
            uint8_t m_x;
            uint8_t m_y;
        #endif
    };
}

#endif //CHESS_BOT_VECTOR_2_HPP


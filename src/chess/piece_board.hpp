//
// Created by bobby on 16/02/2021.
//

#ifndef CHESS_BOT_PIECE_BOARD_HPP
#define CHESS_BOT_PIECE_BOARD_HPP

#include <algorithm>
#include <cassert>

#include "board.hpp"

namespace chess {
    const int PIECE_NUMBER = 16;

    class PieceBoard : public Board {
    public:
        PieceBoard();

        // returns PieceType that was attacked, piece_id is for pieces like pawns that could have multiple pieces on the board
        PieceType attack(PieceType from_piece_type, PieceType to_piece_type, int from_piece_id = 0,
                         int to_piece_id = 0)override;
        PieceType attack(Vector2 from_pos, Vector2 to_pos)override;

        bool is_in_check(bool checking_white)override;
        int get_static_eval()override;
        int get_fast_eval()override;
        GameOutcome game_end_status()override;

        std::vector<Board> possible_states(bool checking_white)override;

        void move(Vector2 from_pos, Vector2 to_pos)override;
        void move(PieceType piece_type, Vector2 to_pos, int piece_id = 0)override;
    private:
        class Piece {
        public:
            // fills with placeholder value to keep the compilers at bay
            Piece() : Piece(true, PieceType::None, Vector2(-1, -1)) {}

            Piece(bool white, PieceType type, Vector2 position) {
                m_position = position;
                m_type = type;
                m_white = white;
            }

            Vector2 get_position() const {
                return m_position;
            }

            PieceType get_type() const {
                return m_type;
            }

            bool is_white() const {
                return m_white;
            }

            void set_position(const Vector2 position) {
                m_position = position;
            }
        private:
            Vector2 m_position;
            PieceType m_type;
            bool m_white;
        };

        std::vector<Vector2> get_attack_positions(Piece &piece);

        const int KING_ARRAY_PLACEMENT = 4;

        Piece m_black_pieces[PIECE_NUMBER];
        Piece m_white_pieces[PIECE_NUMBER];
    };
}

#endif //CHESS_BOT_PIECE_BOARD_HPP

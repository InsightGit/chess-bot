//
// Created by bobby on 16/02/2021.
//

#ifndef CHESS_BOT_BOARD_HPP
#define CHESS_BOT_BOARD_HPP

#include <exception>
#include <vector>

#include "vector_2.hpp"

namespace chess {
    enum class PieceType {
        King,
        Queen,
        Rook,
        Bishop,
        Knight,
        Pawn,
        None
    };

    enum class GameOutcome {
        BlackVictory,
        Tie,
        WhiteVictory,
        InProgress
    };

    class InvalidMoveException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Invalid move attempted";
        }
    };

    class Board {
    public:
        virtual std::vector<Board> possible_states(bool checking_white) = 0;

        // returns PieceType that was attacked, piece_id is for pieces like pawns that could have multiple pieces on the board
        virtual PieceType attack(PieceType from_piece_type, PieceType to_piece_type, int from_piece_id = 0,
                                 int to_piece_id = 0) = 0;
        virtual PieceType attack(Vector2 from_pos, Vector2 to_pos) = 0;

        virtual bool is_in_check(bool checking_white) = 0;

        virtual GameOutcome game_end_status() = 0;
        virtual int get_static_eval() = 0;
        virtual int get_fast_eval() = 0;
        virtual void move(Vector2 from_pos, Vector2 to_pos) = 0;
        virtual void move(PieceType piece_type, Vector2 to_pos, int piece_id = 0) = 0;
    };
}

#endif //CHESS_BOT_BOARD_HPP

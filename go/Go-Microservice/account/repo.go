package account

import (
	"context"
	"database/sql"
	"errors"

	"github.com/go-kit/kit/log"
)

var errRepo = errors.New("error: unable to handle repo request")

type repo struct {
	db     *sql.DB
	logger log.Logger
}

func NewRepo(db *sql.DB, logger log.Logger) Repository {
	return &repo{
		db:     db,
		logger: log.With(logger, "repo", "sql"),
	}
}

func (repo *repo) CreateUser(ctx context.Context, user User) error {
	sql := `
		INSERT INTO "user" (id, email, password) 
		VALUES ($1, $2, $3)`

	if user.Email == "" || user.Password == "" {
		return errRepo
	}

	_, err := repo.db.ExecContext(ctx, sql, user.ID, user.Email, user.Password)
	if err != nil {
		return err
	}

	return nil
}

func (repo *repo) GetUser(ctx context.Context, id string) (string, error) {
	var email string
	err := repo.db.QueryRow("SELECT email FROM \"user\" WHERE id = $1", id).Scan(&email)

	if err != nil {
		return "", errRepo
	}

	return email, nil
}

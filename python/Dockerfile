# Stage 1: build
FROM python:3.12-slim AS builder

# --- Install Poetry ---
ARG POETRY_VERSION=2.1

ENV POETRY_HOME=/opt/poetry
ENV POETRY_VIRTUALENVS_IN_PROJECT=1
ENV POETRY_VIRTUALENVS_CREATE=1
ENV PYTHONDONTWRITEBYTECODE=1
ENV PYTHONUNBUFFERED=1
# Tell Poetry where to place its cache and virtual environment
ENV POETRY_CACHE_DIR=/opt/.cache

RUN pip install "poetry==${POETRY_VERSION}"

WORKDIR /app

COPY pyproject.toml poetry.lock /app/
RUN poetry install --no-root && rm -rf $POETRY_CACHE_DIR

COPY lpg/ lpg/


# Stage 2: final
FROM python:3.12-slim AS final

EXPOSE 8080

WORKDIR /app
ENV VIRTUAL_ENV=/app/.venv
ENV PATH="/app/.venv/bin:$PATH"


COPY --from=builder /app /app

CMD ["uvicorn", "--host", "0.0.0.0", "--port", "8080", "lpg.app:app"]

FROM debian:trixie-slim AS base

FROM base AS deps

RUN apt-get update && \
    apt-get install -y texlive-full make && \
    mktexlsr && \
    (updmap-sys || true)

FROM deps AS runner

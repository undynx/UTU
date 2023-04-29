-- 
--  MySQL database
-- 

CREATE DATABASE BD2_OB1;
USE BD2_OB1;

CREATE TABLE BD2_OB1.casts (
    movie_id bigint NOT NULL,
    person_id bigint NOT NULL,
    job_id bigint NOT NULL,
    role varchar(150) NOT NULL
);


-- ALTER TABLE BD2_OB1.casts OWNER TO postgres;

-- 
--  Name: genres; Type: TABLE; Schema: BD2_OB1; Owner: postgres
-- 

CREATE TABLE BD2_OB1.genres (
    id bigint NOT NULL,
    name text
);


-- ALTER TABLE BD2_OB1.genres OWNER TO postgres;

-- 
--  Name: jobs; Type: TABLE; Schema: BD2_OB1; Owner: postgres
-- 



CREATE TABLE BD2_OB1.jobs (
    id bigint NOT NULL,
    name text
);


-- ALTER TABLE BD2_OB1.jobs OWNER TO postgres;

-- 
--  Name: TABLE jobs; Type: COMMENT; Schema: BD2_OB1; Owner: postgres
-- 

-- COMMENT ON TABLE BD2_OB1.jobs IS 'English-only version of job_names';


-- 
--  Name: movie_genres; Type: TABLE; Schema: BD2_OB1; Owner: postgres
-- 

CREATE TABLE BD2_OB1.movie_genres (
    movie_id bigint NOT NULL,
    genre_id bigint NOT NULL
);


-- ALTER TABLE BD2_OB1.movie_genres OWNER TO postgres;

-- 
--  Name: movie_in_saga; Type: TABLE; Schema: BD2_OB1; Owner: postgres
-- 

CREATE TABLE BD2_OB1.movie_in_saga (
    movie_id bigint NOT NULL,
    saga_id bigint NOT NULL
);


-- ALTER TABLE BD2_OB1.movie_in_saga OWNER TO postgres;

-- 
--  Name: movie_languages; Type: TABLE; Schema: BD2_OB1; Owner: postgres
-- 

CREATE TABLE BD2_OB1.movie_languages (
    movie_id bigint NOT NULL,
    language varchar(150) NOT NULL
);


-- ALTER TABLE BD2_OB1.movie_languages OWNER TO postgres;

-- 
--  Name: movie_references; Type: TABLE; Schema: BD2_OB1; Owner: postgres
-- 

CREATE TABLE BD2_OB1.movie_references (
    reference_to bigint NOT NULL,
    referenced_by bigint NOT NULL,
    type text NOT NULL
);


-- ALTER TABLE BD2_OB1.movie_references OWNER TO postgres;

-- 
--  Name: movies; Type: TABLE; Schema: BD2_OB1; Owner: postgres
-- 

CREATE TABLE BD2_OB1.movies (
    id bigint NOT NULL,
    name text,
    date date,
    runtime integer,
    budget numeric,
    revenue numeric,
    homepage text,
    vote_average numeric
);


-- ALTER TABLE BD2_OB1.movies OWNER TO postgres;

-- 
--  Name: sagas; Type: TABLE; Schema: BD2_OB1; Owner: postgres
-- 

CREATE TABLE BD2_OB1.sagas (
    id bigint NOT NULL,
    name text,
    date date
);


-- ALTER TABLE BD2_OB1.sagas OWNER TO postgres;

-- 
--  Name: people; Type: TABLE; Schema: BD2_OB1; Owner: postgres
-- 

CREATE TABLE BD2_OB1.people (
    id bigint NOT NULL,
    name text,
    birthdate date,
    deathdate date,
    gender integer
);


-- ALTER TABLE BD2_OB1.people OWNER TO postgres;


